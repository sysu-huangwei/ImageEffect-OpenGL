//
//  MultiplyFilter.cpp
//
//  Created by rayyy on 2022/4/1.
//

#include "MultiplyFilter.hpp"

namespace effect {

void MultiplyFilter::init() {
    BaseFilter::initWithVertexStringAndFragmentString("simple", "multiply");
}

void MultiplyFilter::renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) {
    if (isNeedRender() && outputFrameBuffer) {
        outputFrameBuffer->activeFrameBuffer();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        
        program->use();
        
        program->setVertexAttribPointer("a_position", imageVertices);
        program->setVertexAttribPointer("a_texCoord", textureCoordinates);
        
        program->setTextureAtIndex("u_texture", inputFrameBuffers[0]->getTextureID(), 2 + inputFrameBufferIndices[0]);
        program->setTextureAtIndex("u_texture1", inputFrameBuffers[1]->getTextureID(), 2 + inputFrameBufferIndices[1]);
        program->setUniform1f("multiplyOrDivide", (float)multiplyOrDivide);
        program->setUniform1f("eps", (float)eps);
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        
        glBindFramebuffer(GL_FRAMEBUFFER, GL_NONE);
    }
    
    unlockAndClearAllInputFrameBuffers();
}

void MultiplyFilter::setParams(const std::map<std::string, std::string> &param) {
    if (param.find(FilterParam_Multiply_MultiplyOrDivide) != param.end()) {
        multiplyOrDivide = (bool)std::stoi(param.at(FilterParam_Multiply_MultiplyOrDivide));
    }
    if (param.find(FilterParam_Multiply_EPS) != param.end()) {
        eps = std::stof(param.at(FilterParam_Multiply_EPS));
    }
}

bool MultiplyFilter::isAllInputReady() {
    return inputFrameBuffers.size() == 2;
}

}
