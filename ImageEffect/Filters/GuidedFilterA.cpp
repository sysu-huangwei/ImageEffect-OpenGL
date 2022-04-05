//
//  GuidedFilterA.cpp
//
//  Created by rayyy on 2022/4/2.
//

#include "GuidedFilterA.hpp"

namespace effect {

void GuidedFilterA::init() {
    BaseFilter::initWithVertexStringAndFragmentString("simple", "guidedA");
}

void GuidedFilterA::setInputFrameBufferAtIndex(std::shared_ptr<FrameBuffer> inputFrameBuffer, int index) {
    BaseFilter::setInputFrameBufferAtIndex(inputFrameBuffer, index);
    if (inputFrameBuffer) {
        widthOffset = 1.0f / inputFrameBuffer->getWidth();
        heightOffset = 1.0f / inputFrameBuffer->getHeight();
    }
    setOutputSize(firstInputWidth * 2.0, firstInputHeight);
}

void GuidedFilterA::renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) {
    if (isNeedRender() && outputFrameBuffer) {
        outputFrameBuffer->activeFrameBuffer();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        
        program->use();
        
        program->setVertexAttribPointer("a_position", imageVertices);
        program->setVertexAttribPointer("a_texCoord", textureCoordinates);
        
        program->setTextureAtIndex("u_origin", inputFrameBuffers[0]->getTextureID(), 2 + inputFrameBufferIndices[0]);
        program->setUniform1f("alpha", (float)alpha);
        program->setUniform2f("offset", widthOffset, heightOffset);
        program->setUniform1f("eps", (float)eps);
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        
        glBindFramebuffer(GL_FRAMEBUFFER, GL_NONE);
    }
    
    unlockAndClearAllInputFrameBuffers();
}

void GuidedFilterA::setParams(const std::map<std::string, std::string> &param) {
    if (param.find(FilterParam_Multiply_EPS) != param.end()) {
        eps = std::stof(param.at(FilterParam_Multiply_EPS));
    }
    if (param.find(FilterParam_Guided_Alpha) != param.end()) {
        alpha = std::stof(param.at(FilterParam_Guided_Alpha));
    }
}

bool GuidedFilterA::isAllInputReady() {
    return inputFrameBuffers.size() == 1;
}

}
