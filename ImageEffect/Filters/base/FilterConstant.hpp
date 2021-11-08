//
//  FilterConstant.hpp
//
//  Created by rayyyhuang on 2021/7/6.
//

#ifndef FilterConstant_hpp
#define FilterConstant_hpp

#define FilterType_Copy "CopyFilter"
#define FilterType_Lut "LutFilter"
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
#define FilterType_SmallHead "SmallHeadFilter"

#define FilterParam_Lut_Path FilterType_Lut "_Path"
#define FilterParam_Lut_Alpha FilterType_Lut "_Alpha"
#define FilterParam_Mix_Alpha FilterType_Mix "_Alpha"
#define FilterParam_BlurSub_Direction FilterType_BlurSub "_Direction"
#define FilterParam_Blur_Alpha FilterType_Blur "_Alpha"
#define FilterParam_Sharpen_Alpha FilterType_SharpenUSM "_SharpenAlpha"
#define FilterParam_SmallHead_Degree FilterType_SmallHead "_SmallHeadDegree"

#endif /* FilterConstant_hpp */
