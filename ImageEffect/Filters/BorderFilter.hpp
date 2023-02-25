//
//  BorderFilter.hpp
//
//  Created by rayyyhuang on 2023/2/25.
//

#ifndef BorderFilter_hpp
#define BorderFilter_hpp

#include "BaseFilter.hpp"
#include "BaseDefine.h"

namespace effect {

/// 计算图片中边缘的滤镜
class BorderFilter : public BaseFilter {
public:
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_Border; }
    
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

#endif /* BorderFilter_hpp */
