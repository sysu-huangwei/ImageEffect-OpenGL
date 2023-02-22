//
//  CorrectSizeFilter.hpp
//
//  Created by rayyyhuang on 2023/2/21.
//

#ifndef CorrectSizeFilter_hpp
#define CorrectSizeFilter_hpp

#include "BaseFilter.hpp"
#include "BaseDefine.h"

namespace effect {

/// 矫正尺寸的滤镜，使得输入的纹理不变形地被画到输出纹理上。边缘会是黑色。
class CorrectSizeFilter : public BaseFilter {
public:
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_CorrectSize; }
    
    /// 初始化，必须在GL线程，子类实现这个方法去做GL相关的初始化操作
    virtual void init() override;
    
    /// 渲染，必须在GL线程
    /// @param outputFrameBuffer 目标FBO
    virtual void renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) override;
    
    /// 设置参数
    /// @param param 参数
    virtual void setParams(const std::map<std::string, std::string> &param) override;
    
    
protected:
    
    bool needFlipY = false;
    
};

}

#endif /* CorrectSizeFilter_hpp */
