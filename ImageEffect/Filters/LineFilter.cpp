//
//  LineFilter.cpp
//
//  Created by rayyyhuang on 2021/4/20.
//

#include "LineFilter.hpp"
#include <string.h>

namespace effect {

LineFilter::~LineFilter() {
    SAFE_DELETE_ARRAY(this->lines);
}

void LineFilter::init() {
    BaseFilter::initWithVertexStringAndFragmentString("line", "line");
}

void LineFilter::renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) {
    if (isNeedRender() && outputFrameBuffer) {
        outputFrameBuffer->activeFrameBuffer();
        
        program->use();
        
        program->setVertexAttribPointer("a_position", lines);
        
        glLineWidth(5.0f);
        glDrawArrays(GL_LINES, 0, linesCount * 2);
        
        glBindFramebuffer(GL_FRAMEBUFFER, GL_NONE);
    }
    
    unlockAndClearAllInputFrameBuffers();
}


void LineFilter::setLines(std::vector<BaseLine> lines) {
    if ((int)lines.size() != linesCount) {
        SAFE_DELETE_ARRAY(this->lines);
        linesCount = (int)lines.size();
        this->lines = new float[linesCount * 4];
    }
    if (linesCount > 0) {
        memcpy(this->lines, &lines[0], sizeof(BaseLine) * lines.size());
    }
}

bool LineFilter::isNeedRender() {
    return lines && linesCount > 0 && enableRender;
}

}
