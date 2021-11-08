//
//  MixFilter.cpp
//
//  Created by rayyy on 2021/9/27.
//

#include "MixFilter.hpp"

namespace effect {

void MixFilter::init() {
    BaseFilter::initWithVertexStringAndFragmentString("simple", "mix");
}

void MixFilter::renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) {
    if (isNeedRender() && outputFrameBuffer) {
        outputFrameBuffer->activeFrameBuffer();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        
        program->use();
        
        program->setVertexAttribPointer("a_position", imageVertices);
        program->setVertexAttribPointer("a_texCoord", textureCoordinates);
        
        program->setTextureAtIndex("u_texture", inputFrameBuffers[0]->getTextureID(), 2 + inputFrameBufferIndices[0]);
        program->setTextureAtIndex("u_texture1", inputFrameBuffers[1]->getTextureID(), 2 + inputFrameBufferIndices[1]);
        program->setUniform1f("alpha", alpha);
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        
        glBindFramebuffer(GL_FRAMEBUFFER, GL_NONE);
    }
    
    unlockAndClearAllInputFrameBuffers();
}

void MixFilter::setParams(const std::map<std::string, std::string> &param) {
    if (param.find(FilterParam_Mix_Alpha) != param.end()) {
        setAlpha(std::stof(param.at(FilterParam_Mix_Alpha)));
    }
}

void MixFilter::setAlpha(float alpha) {
    this->alpha = alpha;
}

bool MixFilter::isAllInputReady() {
    return inputFrameBuffers.size() == 2;
}

}
