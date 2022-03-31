//
//  MeanFilter.cpp
//
//  Created by rayyy on 2022/3/31.
//

#include "MeanFilter.hpp"

namespace effect {

void MeanFilter::init() {
    BaseFilter::initWithVertexStringAndFragmentString("mean", "mean");
}

void MeanFilter::setInputFrameBufferAtIndex(std::shared_ptr<FrameBuffer> inputFrameBuffer, int index) {
    BaseFilter::setInputFrameBufferAtIndex(inputFrameBuffer, index);
    if (inputFrameBuffer) {
        widthOffset = 1.0f / inputFrameBuffer->getWidth();
        heightOffset = 1.0f / inputFrameBuffer->getHeight();
    }
}

void MeanFilter::renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) {
    if (isNeedRender() && outputFrameBuffer) {
        outputFrameBuffer->activeFrameBuffer();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        
        program->use();
        
        program->setVertexAttribPointer("a_position", imageVertices);
        program->setVertexAttribPointer("a_texCoord", textureCoordinates);
        
        program->setTextureAtIndex("u_texture", inputFrameBuffers[0]->getTextureID(), 2 + inputFrameBufferIndices[0]);
        program->setUniform2f("offset", widthOffset, heightOffset);
        program->setUniform1f("alpha", alpha);
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        
        glBindFramebuffer(GL_FRAMEBUFFER, GL_NONE);
    }
    
    unlockAndClearAllInputFrameBuffers();
}

void MeanFilter::setParams(const std::map<std::string, std::string> &param) {
    if (param.find(FilterParam_Mean_Alpha) != param.end()) {
        alpha = std::stof(param.at(FilterParam_Mean_Alpha));
    }
}

}
