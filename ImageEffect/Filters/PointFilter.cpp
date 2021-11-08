//
//  PointFilter.cpp
//
//  Created by rayyyhuang on 2021/4/16.
//

#include "PointFilter.hpp"
#include <string.h>

namespace effect {

PointFilter::~PointFilter() {
    SAFE_DELETE_ARRAY(this->points);
}

void PointFilter::init() {
    BaseFilter::initWithVertexStringAndFragmentString("point", "point");
}

void PointFilter::renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) {
    if (isNeedRender() && outputFrameBuffer) {
        outputFrameBuffer->activeFrameBuffer();
        
        program->use();
        
        program->setVertexAttribPointer("a_position", points);
        
        glDrawArrays(GL_POINTS, 0, pointsCount);
        
        glBindFramebuffer(GL_FRAMEBUFFER, GL_NONE);
    }
    
    unlockAndClearAllInputFrameBuffers();
}


void PointFilter::setPoints(std::vector<BasePoint> points) {
    if ((int)points.size() != pointsCount) {
        SAFE_DELETE_ARRAY(this->points);
        this->pointsCount = (int)points.size();
        this->points = new float[points.size() * 2];
    }
    if (pointsCount > 0) {
        memcpy(this->points, &points[0], sizeof(BasePoint) * points.size());
    }
}

bool PointFilter::isNeedRender() {
    return points && pointsCount > 0 && enableRender;
}

}
