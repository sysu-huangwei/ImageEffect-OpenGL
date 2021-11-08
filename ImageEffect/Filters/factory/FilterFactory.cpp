//
//  FilterFactory.cpp
//
//  Created by rayyy on 2021/9/23.
//

#include "FilterFactory.hpp"

#include "BaseLog.h"

#include "CopyFilter.hpp"
#include "BlurSubFilter.hpp"
#include "BlurFilter.hpp"
#include "MixFilter.hpp"
#include "SmoothFilter.hpp"
#include "PointFilter.hpp"
#include "BackgroundPointFilter.hpp"
#include "LineFilter.hpp"
#include "BackgroundLineFilter.hpp"
#include "MeshFilter.hpp"
#include "BackgroundMeshFilter.hpp"

namespace effect {
    
std::shared_ptr<BaseFilter> FilterFactory::createFilter(const FilterDescription &filterDesc) {
    std::shared_ptr<BaseFilter> filter = nullptr;
    
    if (filterDesc.type == FilterType_Copy) {
        filter = std::make_shared<CopyFilter>();
    } else if (filterDesc.type == FilterType_BlurSub) {
        filter = std::make_shared<BlurSubFilter>();
    } else if (filterDesc.type == FilterType_Blur) {
        filter = std::make_shared<BlurFilter>();
    } else if (filterDesc.type == FilterType_Mix) {
        filter = std::make_shared<MixFilter>();
    } else if (filterDesc.type == FilterType_Smooth) {
        filter = std::make_shared<SmoothFilter>();
    } else if (filterDesc.type == FilterType_Point) {
        filter = std::make_shared<PointFilter>();
    } else if (filterDesc.type == FilterType_BackgroundPoint) {
        filter = std::make_shared<BackgroundPointFilter>();
    } else if (filterDesc.type == FilterType_Line) {
        filter = std::make_shared<LineFilter>();
    } else if (filterDesc.type == FilterType_BackgroundLine) {
        filter = std::make_shared<BackgroundLineFilter>();
    } else if (filterDesc.type == FilterType_Mesh) {
        filter = std::make_shared<MeshFilter>();
    } else if (filterDesc.type == FilterType_BackgroundMesh) {
        filter = std::make_shared<BackgroundMeshFilter>();
    } else {
        LOGE("Error: FilterFactory::createFilter: invalid filter type = %s", filterDesc.type.c_str());
        assert(false);
    }
    
    filter->setEnableRender(filterDesc.enable);
    filter->setOutputSize(filterDesc.outputWidth, filterDesc.outputHeight);
    filter->setParams(filterDesc.params);
    
    return filter;
}

}
