//
//  LevelFilter.cpp
//
//  Created by rayyy on 2021/11/19.
//

#include "LevelFilter.hpp"

namespace effect {

void LevelFilter::init() {
    BaseFilter::initWithVertexStringAndFragmentString("simple", "level");
}

void LevelFilter::renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) {
    if (isNeedRender() && outputFrameBuffer) {
        outputFrameBuffer->activeFrameBuffer();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        
        program->use();
        
        program->setVertexAttribPointer("a_position", imageVertices);
        program->setVertexAttribPointer("a_texCoord", textureCoordinates);
        
        program->setTextureAtIndex("u_texture", inputFrameBuffers[0]->getTextureID(), 2 + inputFrameBufferIndices[0]);
        
        program->setUniform1f("highLight", highLight);
        program->setUniform1f("shadow", shadow);
        program->setUniform1f("midtone", midtone);
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        
        glBindFramebuffer(GL_FRAMEBUFFER, GL_NONE);
    }
    
    unlockAndClearAllInputFrameBuffers();
}

void LevelFilter::setParams(const std::map<std::string, std::string> &param) {
    if (param.find(FilterParam_Level_HighLight) != param.end()) {
        setHighLight(std::stof(param.at(FilterParam_Level_HighLight)));
    }
    if (param.find(FilterParam_Level_Shadow) != param.end()) {
        setShadow(std::stof(param.at(FilterParam_Level_Shadow)));
    }
    if (param.find(FilterParam_Level_Midtone) != param.end()) {
        setMidtone(std::stof(param.at(FilterParam_Level_Midtone)));
    }
}

void LevelFilter::setHighLight(float highLight) {
    this->highLight = highLight;
}
void LevelFilter::setShadow(float shadow) {
    this->shadow = shadow;
}

void LevelFilter::setMidtone(float midtone) {
    this->midtone = midtone;
}

}
