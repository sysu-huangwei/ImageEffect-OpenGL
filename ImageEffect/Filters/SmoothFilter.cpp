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
    begin.nextIDs.push_back("mix");
    begin.nextTextureIndices.push_back(0);
    begin.nextIDs.push_back("blur");
    begin.nextTextureIndices.push_back(0);
    
    FilterNodeDescription blur;
    blur.id = "blur";
    blur.nextIDs.push_back("mix");
    blur.nextTextureIndices.push_back(1);
    blur.filterDesc.type = FilterType_Blur;
    
    FilterNodeDescription mix;
    mix.id = "mix";
    mix.filterDesc.type = FilterType_Mix;
    
    nodeDescriptions.push_back(begin);
    nodeDescriptions.push_back(blur);
    nodeDescriptions.push_back(mix);
}

void SmoothFilter::setParams(const std::map<std::string, std::string> &param) {
    if (param.find(FilterParam_Blur_Alpha) != param.end()) {
        std::shared_ptr<BaseFilter> mixFilter = getFilterByNodeID("mix");
        if (mixFilter) {
            mixFilter->setParams({{FilterParam_Mix_Alpha, param.at(FilterParam_Blur_Alpha)}});
        }
    }
}

}
