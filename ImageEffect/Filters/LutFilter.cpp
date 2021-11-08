//
//  LutFilter.cpp
//
//  Created by rayyyhuang on 2021/4/14.
//

#include "LutFilter.hpp"
#include "BaseGLUtils.hpp"

namespace effect {

void LutFilter::init() {
    BaseFilter::initWithVertexStringAndFragmentString("simple", "lut");
}

void LutFilter::release() {
    BaseFilter::release();
    if (lutTextureID > 0) {
        glDeleteTextures(1, &lutTextureID);
        lutTextureID = 0;
    }
}

void LutFilter::renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) {
    if (isNeedRender() && outputFrameBuffer) {
        outputFrameBuffer->activeFrameBuffer();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        
        program->use();
        
        program->setVertexAttribPointer("a_position", imageVertices);
        program->setVertexAttribPointer("a_texCoord", textureCoordinates);
        
        program->setTextureAtIndex("u_texture", inputFrameBuffers[0]->getTextureID(), 2 + inputFrameBufferIndices[0]);
        program->setTextureAtIndex("u_lut", lutTextureID, 3);
        
        if (lutTextureID > 0) {
            program->setUniform1f("alpha", alpha);
        } else {
            program->setUniform1f("alpha", 0.0f);
        }
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        
        glBindFramebuffer(GL_FRAMEBUFFER, GL_NONE);
    }
    
    unlockAndClearAllInputFrameBuffers();
}

void LutFilter::setParams(const std::map<std::string, std::string> &param) {
    if (param.find(FilterParam_Lut_Path) != param.end()) {
        setLutImagePath(param.at(FilterParam_Lut_Path));
    }
    if (param.find(FilterParam_Lut_Alpha) != param.end()) {
        setAlpha(std::stof(param.at(FilterParam_Lut_Alpha)));
    }
}

void LutFilter::setLutImagePath(std::string path) {
    if (lutTextureID > 0) {
        glDeleteTextures(1, &lutTextureID);
        lutTextureID = 0;
    }
    int width, height;
    this->lutTextureID = BaseGLUtils::loadImageFileToTexture(path.c_str(), width, height);
}

void LutFilter::setAlpha(float alpha) {
    this->alpha = alpha;
}

}
