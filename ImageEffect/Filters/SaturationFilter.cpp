//
//  SaturationFilter.cpp
//
//  Created by rayyy on 2021/11/17.
//

#include "SaturationFilter.hpp"

namespace effect {

void SaturationFilter::init() {
    BaseFilter::initWithVertexStringAndFragmentString("simple", "saturation");
}

void SaturationFilter::renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) {
    if (isNeedRender() && outputFrameBuffer) {
        outputFrameBuffer->activeFrameBuffer();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        
        program->use();
        
        program->setVertexAttribPointer("a_position", imageVertices);
        program->setVertexAttribPointer("a_texCoord", textureCoordinates);
        
        program->setTextureAtIndex("u_texture", inputFrameBuffers[0]->getTextureID(), 2 + inputFrameBufferIndices[0]);
        
        program->setUniform1f("saturation", alpha);
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        
        glBindFramebuffer(GL_FRAMEBUFFER, GL_NONE);
    }
    
    unlockAndClearAllInputFrameBuffers();
}

void SaturationFilter::setParams(const std::map<std::string, std::string> &param) {
    if (param.find(FilterParam_Saturation_Alpha) != param.end()) {
        setAlpha(std::stof(param.at(FilterParam_Saturation_Alpha)));
    }
}

void SaturationFilter::setAlpha(float alpha) {
    this->alpha = alpha;
}

}
