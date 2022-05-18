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
    BaseFilter::initWithVertexStringAndFragmentString("simple", "simple");
}

void PointFilter::renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) {
    if (isNeedRender() && outputFrameBuffer) {
        outputFrameBuffer->activeFrameBuffer();
        
//        glClear(GL_COLOR_BUFFER_BIT);
//        glClearColor(0.0f,1.0f,0.0f,1.0f);
        
        program->use();

        program->setVertexAttribPointer("a_position", imageVertices);
        program->setVertexAttribPointer("a_texCoord", textureCoordinates);

        program->setTextureAtIndex("u_texture", inputFrameBuffers[0]->getTextureID(), 2 + inputFrameBufferIndices[0]);

        glDrawArrays(GL_POINTS, 0, 4);

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
        for (int i = 0; i < pointsCount; i++) {
            this->points[2 * i] = points[i].x;
            this->points[2 * i + 1] = points[i].y;
        }
    }
}

bool PointFilter::isNeedRender() {
    return points && pointsCount > 0 && enableRender;
}

}
