//
//  GuidedFilter.hpp
//
//  Created by rayyy on 2022/4/2.
//

#ifndef GuidedFilter_hpp
#define GuidedFilter_hpp

#include "BaseFilter.hpp"

namespace effect {

/// 导向滤波
class GuidedFilter : public BaseFilter {
public:
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_GuidedFilter; }
    
    /// 初始化，必须在GL线程，子类实现这个方法去做GL相关的初始化操作
    virtual void init() override;
    
    /// 渲染，必须在GL线程
    /// @param outputFrameBuffer 目标FBO
    virtual void renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) override;
    
protected:
    
    /// 是否所有输入已就绪
    virtual bool isAllInputReady() override;
};

}

#endif /* GuidedFilter_hpp */
