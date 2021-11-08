//
//  MixFilter.hpp
//
//  Created by rayyy on 2021/9/27.
//

#ifndef MixFilter_hpp
#define MixFilter_hpp

#include "BaseFilter.hpp"

namespace effect {

/// 模糊
class MixFilter : public BaseFilter {
public:
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_Mix; }
    
    /// 初始化，必须在GL线程，子类实现这个方法去做GL相关的初始化操作
    virtual void init() override;
    
    /// 渲染，必须在GL线程
    /// @param outputFrameBuffer 目标FBO
    virtual void renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) override;
    
    /// 设置参数
    /// @param param 参数
    virtual void setParams(const std::map<std::string, std::string> &param) override;
    
    
protected:
    
    float alpha = 0.0f;
    
    /// 设置混合程度，0.0：第一个输入   1.0：第二个输入   0.5：各一半
    /// @param alpha 混合程度
    void setAlpha(float alpha);
    
    /// 是否所有输入已就绪
    virtual bool isAllInputReady() override;
};

}

#endif /* MixFilter_hpp */
