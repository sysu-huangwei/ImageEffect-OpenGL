//
//  SmoothMixFilter.hpp
//
//  Created by rayyyhuang on 2023/2/25.
//

#ifndef SmoothMixFilter_hpp
#define SmoothMixFilter_hpp

#include "BaseFilter.hpp"
#include "BaseDefine.h"

namespace effect {

/// 磨皮最终混合滤镜
class SmoothMixFilter : public BaseFilter {
public:
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_SmoothMix; }
    
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
    
    /// 设置效果程度
    /// @param alpha 效果程度
    void setAlpha(float alpha);
    
    /// 是否所有输入已就绪
    virtual bool isAllInputReady() override;
};

}


#endif /* SmoothMixFilter_hpp */
