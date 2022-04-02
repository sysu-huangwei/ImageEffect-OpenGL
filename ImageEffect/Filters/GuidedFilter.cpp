//
//  GuidedFilter.cpp
//
//  Created by rayyy on 2022/4/2.
//

#include "GuidedFilter.hpp"

namespace effect {

void GuidedFilter::init() {
    BaseFilter::initWithVertexStringAndFragmentString("simple", "guided");
}

void GuidedFilter::renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) {
    if (isNeedRender() && outputFrameBuffer) {
        outputFrameBuffer->activeFrameBuffer();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        
        program->use();
        
        program->setVertexAttribPointer("a_position", imageVertices);
        program->setVertexAttribPointer("a_texCoord", textureCoordinates);
        
        program->setTextureAtIndex("u_origin", inputFrameBuffers[0]->getTextureID(), 2 + inputFrameBufferIndices[0]);
        program->setTextureAtIndex("u_meanA", inputFrameBuffers[1]->getTextureID(), 2 + inputFrameBufferIndices[1]);
        program->setTextureAtIndex("u_meanB", inputFrameBuffers[2]->getTextureID(), 2 + inputFrameBufferIndices[2]);
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        
        glBindFramebuffer(GL_FRAMEBUFFER, GL_NONE);
    }
    
    unlockAndClearAllInputFrameBuffers();
}

bool GuidedFilter::isAllInputReady() {
    return inputFrameBuffers.size() == 3;
}

}
