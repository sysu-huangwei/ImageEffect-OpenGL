//
//  MeanFilter.hpp
//
//  Created by rayyy on 2022/3/31.
//

#ifndef MeanFilter_hpp
#define MeanFilter_hpp

#include "BaseFilter.hpp"

namespace effect {

/// 均值模糊
class MeanFilter : public BaseFilter {
public:
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_Mean; }
    
    /// 初始化，必须在GL线程，子类实现这个方法去做GL相关的初始化操作
    virtual void init() override;
    
    /// 设置输入图像的FBO
    /// @param inputFrameBuffer 输入图像的FBO
    /// @param index 这个输入的FBO纹理应该设置到当前滤镜shader的第几个位置，从0开始（通常用于多路输入的滤镜）
    virtual void setInputFrameBufferAtIndex(std::shared_ptr<FrameBuffer> inputFrameBuffer, int index = 0) override;
    
    /// 渲染，必须在GL线程
    /// @param outputFrameBuffer 目标FBO
    virtual void renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) override;
    
    /// 设置参数
    /// @param param 参数
    virtual void setParams(const std::map<std::string, std::string> &param) override;
    
    
protected:
    float alpha = 1.0f;
    float widthOffset = 0.0f, heightOffset = 0.0f;
};

}

#endif /* MeanFilter_hpp */
