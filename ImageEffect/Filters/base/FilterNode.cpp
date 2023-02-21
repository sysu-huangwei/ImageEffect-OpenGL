//
//  FilterNode.cpp
//
//  Created by rayyy on 2021/9/24.
//

#include "FilterNode.hpp"
#include "FilterFactory.hpp"

namespace effect {

FilterNode::FilterNode(const FilterNodeDescription &nodeDesc) {
    id = nodeDesc.id;
    if (nodeDesc.id != defaultBeginID) {
        filter = FilterFactory::createFilter(nodeDesc.filterDesc);
    }
}

void FilterNode::render() {
    if (id != defaultBeginID) {
        if (outputFrameBuffer) {
            filter->renderToFrameBuffer(outputFrameBuffer);
            setResultFrameBufferToNextNodes(outputFrameBuffer);
        } else {
            std::shared_ptr<FrameBuffer> output = filter->render();
            setResultFrameBufferToNextNodes(output);
            output->unlock();
        }
    }
    informNextNodesToRender();
}

void FilterNode::setOutputFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) {
    this->outputFrameBuffer = outputFrameBuffer;
    // 这里重新设置一次是为了子类在渲染的时候可能还需要在这个setOutputSize方法里设置其他需要的数据
    filter->setOutputSize(outputFrameBuffer->getWidth(), outputFrameBuffer->getHeight());
}

void FilterNode::setResultFrameBufferToNextNodes(std::shared_ptr<FrameBuffer> resultFrameBuffer) {
    for (size_t i = 0; i < nextNodes.size(); i++) {
        if (i < nextIndices.size()) {
            nextNodes[i]->filter->setInputFrameBufferAtIndex(resultFrameBuffer, nextIndices[i]);
        } else {
            nextNodes[i]->filter->setInputFrameBufferAtIndex(resultFrameBuffer);
        }
    }
}

void FilterNode::informNextNodesToRender() {
    for (size_t i = 0; i < nextNodes.size(); i++) {
        if (nextNodes[i]->filter->isAllInputReady()) {
            nextNodes[i]->render();
        }
    }
}

}
