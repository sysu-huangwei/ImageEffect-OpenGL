//
//  AddFilter.cpp
//
//  Created by rayyy on 2022/4/1.
//

#include "AddFilter.hpp"

namespace effect {

void AddFilter::init() {
    BaseFilter::initWithVertexStringAndFragmentString("simple", "add");
}

void AddFilter::renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) {
    if (isNeedRender() && outputFrameBuffer) {
        outputFrameBuffer->activeFrameBuffer();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        
        program->use();
        
        program->setVertexAttribPointer("a_position", imageVertices);
        program->setVertexAttribPointer("a_texCoord", textureCoordinates);
        
        program->setTextureAtIndex("u_texture", inputFrameBuffers[0]->getTextureID(), 2 + inputFrameBufferIndices[0]);
        program->setTextureAtIndex("u_texture1", inputFrameBuffers[1]->getTextureID(), 2 + inputFrameBufferIndices[1]);
        program->setUniform1f("addOrSubstract", (float)addOrSubstract);
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        
        glBindFramebuffer(GL_FRAMEBUFFER, GL_NONE);
    }
    
    unlockAndClearAllInputFrameBuffers();
}

void AddFilter::setParams(const std::map<std::string, std::string> &param) {
    if (param.find(FilterParam_Add_AddOrSubstract) != param.end()) {
        addOrSubstract = (bool)std::stoi(param.at(FilterParam_Add_AddOrSubstract));
    }
}

bool AddFilter::isAllInputReady() {
    return inputFrameBuffers.size() == 2;
}

}
