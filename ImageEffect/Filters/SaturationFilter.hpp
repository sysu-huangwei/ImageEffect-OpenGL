//
//  SaturationFilter.hpp
//  ImageEffect
//
//  Created by rayyy on 2021/11/17.
//

#ifndef SaturationFilter_hpp
#define SaturationFilter_hpp

#include "BaseFilter.hpp"

namespace effect {

/// 饱和度
class SaturationFilter : public BaseFilter {
public:
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_Contrast; }
    
    /// 初始化，必须在GL线程，子类实现这个方法去做GL相关的初始化操作
    virtual void init() override;
    
    /// 渲染，必须在GL线程
    /// @param outputFrameBuffer 目标FBO
    virtual void renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) override;
    
    /// 设置参数
    /// @param param 参数
    virtual void setParams(const std::map<std::string, std::string> &param) override;
    
    /// 设置饱和度，-1.0 ~ 1.0
    /// @param alpha 饱和度，-1.0 ~ 1.0
    void setAlpha(float alpha);

private:
    
    float alpha = 0.0f;
};

}

#endif /* SaturationFilter_hpp */
