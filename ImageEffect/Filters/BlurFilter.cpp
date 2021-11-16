//
//  BlurFilter.cpp
//
//  Created by rayyyhuang on 2021/8/16.
//

#include "BlurFilter.hpp"
#include "BaseDefine.h"
#include "BlurSubFilter.hpp"
#include "BaseGLUtils.hpp"
#include "EffectConfigParser.hpp"

namespace effect {

BlurFilter::BlurFilter() {
    std::string json = BaseGLUtils::getFilterDescriptionByName("BlurFilter");
    nodeDescriptions = EffectConfigParser::parseJsonToDescription(json);
}

void BlurFilter::setOutputSize(int outputWidth, int outputHeight) {
    scaleWH(outputWidth, outputHeight);
    FilterChain::setOutputSize(outputWidth, outputHeight);
    std::shared_ptr<BaseFilter> blurHFilter = getFilterByNodeID("blurH");
    if (blurHFilter) {
        blurHFilter->setOutputSize(outputWidth, outputHeight);
    }
    std::shared_ptr<BaseFilter> blurVFilter = getFilterByNodeID("blurV");
    if (blurVFilter) {
        blurVFilter->setOutputSize(outputWidth, outputHeight);
    }
}

void BlurFilter::scaleWH(int &width, int &height, int maxLength) {
    int shortEdge = std::min(width, height);
    float scale = (float)maxLength / (float)shortEdge;
    width = (int)((float)width * scale);
    height = (int)((float)height * scale);
}

}
