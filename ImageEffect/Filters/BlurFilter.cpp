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
    FilterNodeDescription begin = defaultBeginNodeDescription;
    begin.nextIDs.push_back("blurH");
    begin.nextTextureIndices.push_back(0);
    
    FilterNodeDescription blurH;
    blurH.id = "blurH";
    blurH.nextIDs.push_back("blurV");
    blurH.nextTextureIndices.push_back(0);
    blurH.filterDesc.type = FilterType_BlurSub;
    blurH.filterDesc.params = {{FilterParam_BlurSub_Direction, "0"}};
    
    FilterNodeDescription blurV;
    blurV.id = "blurV";
    blurV.filterDesc.type = FilterType_BlurSub;
    blurV.filterDesc.params = {{FilterParam_BlurSub_Direction, "1"}};
    
    
    nodeDescriptions.push_back(begin);
    nodeDescriptions.push_back(blurH);
    nodeDescriptions.push_back(blurV);
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
