//
//  FilterConstant.hpp
//
//  Created by rayyyhuang on 2021/7/6.
//

#ifndef FilterConstant_hpp
#define FilterConstant_hpp

#define FilterType_Copy "CopyFilter"
#define FilterType_Brightness "BrightnessFilter"
#define FilterType_Contrast "ContrastFilter"
#define FilterType_Level "LevelFilter"
#define FilterType_Saturation "SaturationFilter"
#define FilterType_Lut "LutFilter"
#define FilterType_Mean "MeanFilter"
#define FilterType_Add "AddFilter"
#define FilterType_Multiply "MultiplyFilter"
#define FilterType_Variance "VarianceFilter"
#define FilterType_GuidedSubFilter1 "GuidedSubFilter1"
#define FilterType_GuidedSubFilter2 "GuidedSubFilter2"
#define FilterType_GuidedFilter "GuidedFilter"
#define FilterType_BlurSub "BlurSubFilter"
#define FilterType_Blur "BlurFilter"
#define FilterType_Mix "MixFilter"
#define FilterType_Smooth "SmoothFilter"
#define FilterType_SharpenUSM "SharpenUSMFilter"
#define FilterType_Point "PointFilter"
#define FilterType_BackgroundPoint "BackgroundPointFilter"
#define FilterType_FacePoint "FacePointFilter"
#define FilterType_Line "LineFilter"
#define FilterType_BackgroundLine "BackgroundLineFilter"
#define FilterType_FaceLine "FaceLineFilter"
#define FilterType_Mesh "MeshFilter"
#define FilterType_BackgroundMesh "BackgroundMeshFilter"
#define FilterType_Sticker "StickerFilter"
#define FilterType_CorrectSize "CorrectSizeFilter"
#define FilterType_SmallHead "SmallHeadFilter"

#define FilterParam_Brightness_Alpha FilterType_Brightness "_Alpha"
#define FilterParam_Contrast_Alpha FilterType_Contrast "_Alpha"
#define FilterParam_Saturation_Alpha FilterType_Saturation "_Alpha"
#define FilterParam_Level_HighLight FilterType_Level "_HighLight"
#define FilterParam_Level_Shadow FilterType_Level "_Shadow"
#define FilterParam_Level_Midtone FilterType_Level "_Midtone"
#define FilterParam_Lut_Path FilterType_Lut "_Path"
#define FilterParam_Lut_Alpha FilterType_Lut "_Alpha"
#define FilterParam_Mix_Alpha FilterType_Mix "_Alpha"
#define FilterParam_Guided_Alpha FilterType_GuidedFilter "_Alpha"
#define FilterParam_BlurSub_Direction FilterType_BlurSub "_Direction"
#define FilterParam_Blur_Alpha FilterType_Blur "_Alpha"
#define FilterParam_Mean_Alpha FilterType_Mean "_Alpha"
#define FilterParam_Add_AddOrSubstract FilterType_Add "_AddOrSubstract"
#define FilterParam_Multiply_MultiplyOrDivide FilterType_Multiply "_MultiplyOrDivide"
#define FilterParam_Multiply_EPS FilterType_Multiply "_EPS"
#define FilterParam_Sharpen_Alpha FilterType_SharpenUSM "_SharpenAlpha"
#define FilterParam_Sticker_Path FilterType_Sticker "_Path"
#define FilterParam_Sticker_Alpha FilterType_Sticker "_Alpha"
#define FilterParam_CorrectSize_FlipY FilterType_CorrectSize "_FlipY"
#define FilterParam_SmallHead_Degree FilterType_SmallHead "_SmallHeadDegree"

#endif /* FilterConstant_hpp */
