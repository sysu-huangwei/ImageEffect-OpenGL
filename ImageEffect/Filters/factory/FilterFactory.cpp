//
//  FilterFactory.cpp
//
//  Created by rayyy on 2021/9/23.
//

#include "FilterFactory.hpp"

#include "BaseLog.h"

#include "CopyFilter.hpp"
#include "LutFilter.hpp"
#include "BrightnessFilter.hpp"
#include "ContrastFilter.hpp"
#include "SaturationFilter.hpp"
#include "LevelFilter.hpp"
#include "SharpenFilter.hpp"
#include "AddFilter.hpp"
#include "MultiplyFilter.hpp"
#include "VarianceFilter.hpp"
#include "MeanFilter.hpp"
#include "GuidedSubFilter1.hpp"
#include "GuidedSubFilter2.hpp"
#include "GuidedFilter.hpp"
#include "BlurSubFilter.hpp"
#include "BlurFilter.hpp"
#include "BorderFilter.hpp"
#include "MixFilter.hpp"
#include "SmoothMixFilter.hpp"
#include "SmoothFilter.hpp"
#include "PointFilter.hpp"
#include "BackgroundPointFilter.hpp"
#include "LineFilter.hpp"
#include "BackgroundLineFilter.hpp"
#include "MeshFilter.hpp"
#include "BackgroundMeshFilter.hpp"
#include "StickerFilter.hpp"
#include "CorrectSizeFilter.hpp"

namespace effect {
    
std::shared_ptr<BaseFilter> FilterFactory::createFilter(const FilterDescription &filterDesc) {
    std::shared_ptr<BaseFilter> filter = nullptr;
    
    if (filterDesc.type == FilterType_Copy) {
        filter = std::make_shared<CopyFilter>();
    } else if (filterDesc.type == FilterType_Lut) {
        filter = std::make_shared<LutFilter>();
    } else if (filterDesc.type == FilterType_Brightness) {
        filter = std::make_shared<BrightnessFilter>();
    } else if (filterDesc.type == FilterType_Contrast) {
        filter = std::make_shared<ContrastFilter>();
    } else if (filterDesc.type == FilterType_Saturation) {
        filter = std::make_shared<SaturationFilter>();
    } else if (filterDesc.type == FilterType_Level) {
        filter = std::make_shared<LevelFilter>();
    } else if (filterDesc.type == FilterType_SharpenUSM) {
        filter = std::make_shared<SharpenFilter>();
    } else if (filterDesc.type == FilterType_Multiply) {
        filter = std::make_shared<MultiplyFilter>();
    } else if (filterDesc.type == FilterType_Add) {
        filter = std::make_shared<AddFilter>();
    } else if (filterDesc.type == FilterType_Variance) {
        filter = std::make_shared<VarianceFilter>();
    } else if (filterDesc.type == FilterType_Mean) {
        filter = std::make_shared<MeanFilter>();
    } else if (filterDesc.type == FilterType_GuidedSubFilter1) {
        filter = std::make_shared<GuidedSubFilter1>();
    } else if (filterDesc.type == FilterType_GuidedSubFilter2) {
        filter = std::make_shared<GuidedSubFilter2>();
    } else if (filterDesc.type == FilterType_GuidedFilter) {
        filter = std::make_shared<GuidedFilter>();
    } else if (filterDesc.type == FilterType_BlurSub) {
        filter = std::make_shared<BlurSubFilter>();
    } else if (filterDesc.type == FilterType_Blur) {
        filter = std::make_shared<BlurFilter>();
    } else if (filterDesc.type == FilterType_Mix) {
        filter = std::make_shared<MixFilter>();
    } else if (filterDesc.type == FilterType_Border) {
        filter = std::make_shared<BorderFilter>();
    } else if (filterDesc.type == FilterType_SmoothMix) {
        filter = std::make_shared<SmoothMixFilter>();
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
    } else if (filterDesc.type == FilterType_Sticker) {
        filter = std::make_shared<StickerFilter>();
    } else if (filterDesc.type == FilterType_CorrectSize) {
        filter = std::make_shared<CorrectSizeFilter>();
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
