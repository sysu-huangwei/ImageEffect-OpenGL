//
//  LutFilter.hpp
//
//  Created by rayyyhuang on 2021/4/14.
//

#ifndef LutFilter_hpp
#define LutFilter_hpp

#include "BaseFilter.hpp"

namespace effect {

/// LUT
class LutFilter : public BaseFilter {
public:
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_Lut; }
    
    /// 初始化，必须在GL线程，子类实现这个方法去做GL相关的初始化操作
    virtual void init() override;
    
    /// 释放资源，必须在GL线程，子类实现这个方法去做GL相关的释放操作
    virtual void release() override;
    
    /// 渲染，必须在GL线程
    /// @param outputFrameBuffer 目标FBO
    virtual void renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) override;
    
    /// 设置参数
    /// @param param 参数
    virtual void setParams(const std::map<std::string, std::string> &param) override;
    
protected:
    unsigned lutTextureID = 0;
    float alpha = 1.0f;
    
    /// 设置LUT图路径，底层加载
    /// @param path LUT图的路径
    void setLutImagePath(std::string path);
    
    /// 设置滤镜程度
    /// @param alpha 滤镜程度，0.0 ~ 1.0
    void setAlpha(float alpha);
};

}

#endif /* LutFilter_hpp */
