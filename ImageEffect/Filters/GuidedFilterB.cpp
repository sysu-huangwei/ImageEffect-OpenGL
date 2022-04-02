//
//  GuidedFilterB.cpp
//
//  Created by rayyy on 2022/4/2.
//

#include "GuidedFilterB.hpp"

namespace effect {

void GuidedFilterB::init() {
    BaseFilter::initWithVertexStringAndFragmentString("simple", "guidedB");
}

void GuidedFilterB::renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) {
    if (isNeedRender() && outputFrameBuffer) {
        outputFrameBuffer->activeFrameBuffer();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        
        program->use();
        
        program->setVertexAttribPointer("a_position", imageVertices);
        program->setVertexAttribPointer("a_texCoord", textureCoordinates);
        
        program->setTextureAtIndex("u_originMean", inputFrameBuffers[0]->getTextureID(), 2 + inputFrameBufferIndices[0]);
        program->setTextureAtIndex("u_A", inputFrameBuffers[1]->getTextureID(), 2 + inputFrameBufferIndices[1]);
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        
        glBindFramebuffer(GL_FRAMEBUFFER, GL_NONE);
    }
    
    unlockAndClearAllInputFrameBuffers();
}

bool GuidedFilterB::isAllInputReady() {
    return inputFrameBuffers.size() == 2;
}

}
