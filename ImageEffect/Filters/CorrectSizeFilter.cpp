//
//  CorrectSizeFilter.cpp
//
//  Created by rayyyhuang on 2023/2/21.
//

#include "CorrectSizeFilter.hpp"

namespace effect {

void CorrectSizeFilter::init() {
    BaseFilter::initWithVertexStringAndFragmentString("correct", "simple");
}

void CorrectSizeFilter::renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) {
    if (isNeedRender() && outputFrameBuffer) {
        outputFrameBuffer->activeFrameBuffer();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        
        program->use();
        
        if (needFlipY) {
            program->setVertexAttribPointer("a_position", imageVerticesFlipY);
        } else {
            program->setVertexAttribPointer("a_position", imageVertices);
        }
        program->setVertexAttribPointer("a_texCoord", textureCoordinates);
        
        float inputWHRatio = (float)inputFrameBuffers[0]->getWidth() / (float)inputFrameBuffers[0]->getHeight();
        float outputWHRatio = (float)outputFrameBuffer->getWidth() / (float)outputFrameBuffer->getHeight();
//        if (inputWHRatio > outputWHRatio) {
//            program->setUniform2f("correctFactor", 1.0, outputWHRatio / inputWHRatio);
//        } else {
//            program->setUniform2f("correctFactor", inputWHRatio / outputWHRatio, 1.0);
//        }
        program->setUniform2f("correctFactor", inputWHRatio / outputWHRatio, outputWHRatio / inputWHRatio);
        
        
        program->setTextureAtIndex("u_texture", inputFrameBuffers[0]->getTextureID(), 2 + inputFrameBufferIndices[0]);
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        
        glBindFramebuffer(GL_FRAMEBUFFER, GL_NONE);
    }
    
    unlockAndClearAllInputFrameBuffers();
}

void CorrectSizeFilter::setParams(const std::map<std::string, std::string> &param) {
    if (param.find(FilterParam_CorrectSize_FlipY) != param.end()) {
        needFlipY = std::stoi(param.at(FilterParam_CorrectSize_FlipY));
    }
}

}
