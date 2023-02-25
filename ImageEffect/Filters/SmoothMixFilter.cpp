//
//  SmoothMixFilter.cpp
//
//  Created by rayyyhuang on 2023/2/25.
//

#include "SmoothMixFilter.hpp"

namespace effect {

void SmoothMixFilter::init() {
    BaseFilter::initWithVertexStringAndFragmentString("simple", "smooth_mix");
}

void SmoothMixFilter::renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) {
    if (isNeedRender() && outputFrameBuffer) {
        outputFrameBuffer->activeFrameBuffer();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        
        program->use();
        
        program->setVertexAttribPointer("a_position", imageVertices);
        program->setVertexAttribPointer("a_texCoord", textureCoordinates);
        
        program->setTextureAtIndex("u_texture", inputFrameBuffers[0]->getTextureID(), 2 + inputFrameBufferIndices[0]);
        program->setTextureAtIndex("u_blur", inputFrameBuffers[1]->getTextureID(), 2 + inputFrameBufferIndices[1]);
        program->setTextureAtIndex("u_border", inputFrameBuffers[2]->getTextureID(), 2 + inputFrameBufferIndices[2]);
        program->setUniform1f("alpha", alpha);
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        
        glBindFramebuffer(GL_FRAMEBUFFER, GL_NONE);
    }
    
    unlockAndClearAllInputFrameBuffers();
}

void SmoothMixFilter::setParams(const std::map<std::string, std::string> &param) {
    if (param.find(FilterParam_Smooth_Alpha) != param.end()) {
        setAlpha(std::stof(param.at(FilterParam_Smooth_Alpha)));
    }
}

void SmoothMixFilter::setAlpha(float alpha) {
    this->alpha = alpha;
}

bool SmoothMixFilter::isAllInputReady() {
    return inputFrameBuffers.size() == 3;
}

}
