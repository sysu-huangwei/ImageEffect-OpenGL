//
//  AddFilter.hpp
//  ImageEffect
//
//  Created by rayyy on 2022/4/1.
//

#ifndef AddFilter_hpp
#define AddFilter_hpp

#include "BaseFilter.hpp"

namespace effect {

/// 相加
class AddFilter : public BaseFilter {
public:
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_Add; }
    
    /// 初始化，必须在GL线程，子类实现这个方法去做GL相关的初始化操作
    virtual void init() override;
    
    /// 渲染，必须在GL线程
    /// @param outputFrameBuffer 目标FBO
    virtual void renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) override;
    
protected:
    // true: 加  false: 减
    bool addOrSubstract = true;
    
    /// 是否所有输入已就绪
    virtual bool isAllInputReady() override;
    
    /// 设置参数
    /// @param param 参数
    virtual void setParams(const std::map<std::string, std::string> &param) override;
};

}

#endif /* AddFilter_hpp */
