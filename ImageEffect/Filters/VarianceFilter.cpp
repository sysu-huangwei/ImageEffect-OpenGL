//
//  VarianceFilter.cpp
//
//  Created by rayyy on 2022/4/1.
//

#include "VarianceFilter.hpp"

namespace effect {

VarianceFilter::VarianceFilter() {
    FilterNodeDescription begin = defaultBeginNodeDescription;
    begin.nextIDs.push_back("origin2");
    begin.nextTextureIndices.push_back(0);
    begin.nextIDs.push_back("origin2");
    begin.nextTextureIndices.push_back(1);
    begin.nextIDs.push_back("originMean");
    begin.nextTextureIndices.push_back(0);
    
    FilterNodeDescription origin2;
    origin2.id = "origin2";
    origin2.nextIDs.push_back("origin2mean");
    origin2.nextTextureIndices.push_back(0);
    origin2.filterDesc.type = FilterType_Multiply;
    
    FilterNodeDescription origin2mean;
    origin2mean.id = "origin2mean";
    origin2mean.nextIDs.push_back("sub");
    origin2mean.nextTextureIndices.push_back(0);
    origin2mean.filterDesc.type = FilterType_Mean;
    origin2mean.filterDesc.params[FilterParam_Mean_Alpha] = "1";
    
    FilterNodeDescription originMean;
    originMean.id = "originMean";
    originMean.nextIDs.push_back("originMean2");
    originMean.nextTextureIndices.push_back(0);
    originMean.nextIDs.push_back("originMean2");
    originMean.nextTextureIndices.push_back(1);
    originMean.filterDesc.type = FilterType_Mean;
    originMean.filterDesc.params[FilterParam_Mean_Alpha] = "1";
    
    FilterNodeDescription originMean2;
    originMean2.id = "originMean2";
    originMean2.nextIDs.push_back("sub");
    originMean2.nextTextureIndices.push_back(1);
    originMean2.filterDesc.type = FilterType_Multiply;
    
    FilterNodeDescription sub;
    sub.id = "sub";
    sub.filterDesc.type = FilterType_Add;
    sub.filterDesc.params[FilterParam_Add_AddOrSubstract] = "0";
    
    nodeDescriptions.push_back(begin);
    nodeDescriptions.push_back(origin2);
    nodeDescriptions.push_back(origin2mean);
    nodeDescriptions.push_back(originMean);
    nodeDescriptions.push_back(originMean2);
    nodeDescriptions.push_back(sub);
}


}

