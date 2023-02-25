//
//  SmoothFilter.cpp
//
//  Created by Ray on 2021/8/22.
//

#include "SmoothFilter.hpp"
#include "MixFilter.hpp"

namespace effect {

SmoothFilter::SmoothFilter() {
    FilterNodeDescription begin = defaultBeginNodeDescription;
    begin.nextIDs.push_back("smoothMix");
    begin.nextTextureIndices.push_back(0);
    begin.nextIDs.push_back("blurOrigin");
    begin.nextTextureIndices.push_back(0);
    begin.nextIDs.push_back("border");
    begin.nextTextureIndices.push_back(0);
    
    FilterNodeDescription blurOrigin;
    blurOrigin.id = "blurOrigin";
    blurOrigin.nextIDs.push_back("border");
    blurOrigin.nextTextureIndices.push_back(1);
    blurOrigin.nextIDs.push_back("smoothMix");
    blurOrigin.nextTextureIndices.push_back(1);
    blurOrigin.filterDesc.type = FilterType_Blur;
    
    FilterNodeDescription border;
    border.id = "border";
    border.nextIDs.push_back("blurBorder");
    border.nextTextureIndices.push_back(1);
    border.filterDesc.type = FilterType_Border;
    
    FilterNodeDescription blurBorder;
    blurBorder.id = "blurBorder";
    blurBorder.nextIDs.push_back("smoothMix");
    blurBorder.nextTextureIndices.push_back(2);
    blurBorder.filterDesc.type = FilterType_Blur;
    
    FilterNodeDescription smoothMix;
    smoothMix.id = "smoothMix";
    smoothMix.filterDesc.type = FilterType_SmoothMix;
    
    nodeDescriptions.push_back(begin);
    nodeDescriptions.push_back(blurOrigin);
    nodeDescriptions.push_back(border);
    nodeDescriptions.push_back(blurBorder);
    nodeDescriptions.push_back(smoothMix);
}

void SmoothFilter::setParams(const std::map<std::string, std::string> &param) {
    if (param.find(FilterParam_Smooth_Alpha) != param.end()) {
        std::shared_ptr<BaseFilter> smoothMixFilter = getFilterByNodeID("smoothMix");
        if (smoothMixFilter) {
            smoothMixFilter->setParams(param);
        }
    }
}

}
