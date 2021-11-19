//
//  LevelFilter.hpp
//
//  Created by rayyy on 2021/11/19.
//

#ifndef LevelFilter_hpp
#define LevelFilter_hpp

#include "BaseFilter.hpp"

namespace effect {

/// 色阶
class LevelFilter : public BaseFilter {
public:
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_Level; }
    
    /// 初始化，必须在GL线程，子类实现这个方法去做GL相关的初始化操作
    virtual void init() override;
    
    /// 渲染，必须在GL线程
    /// @param outputFrameBuffer 目标FBO
    virtual void renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) override;
    
    /// 设置参数
    /// @param param 参数
    virtual void setParams(const std::map<std::string, std::string> &param) override;
    
    /// 设置高光参数 0.0 ~ 1.0
    /// @param highLight 高光参数 0.0 ~ 1.0
    void setHighLight(float highLight);
    
    /// 设置阴影参数 0.0 ~ 1.0
    /// @param shadow 阴影参数 0.0 ~ 1.0
    void setShadow(float shadow);
    
    /// 设置中间调参数 0.01 ~ 9.99
    /// @param midtone 中间调参数 0.01 ~ 9.99
    void setMidtone(float midtone);

private:
    
    float highLight = 1.0f;  // 高光参数 0.0 ~ 1.0
    float shadow = 0.0f;     // 阴影参数 0.0 ~ 1.0
    float midtone = 1.0f;    // 中间调参数 0.01 ~ 9.99
};

}


#endif /* LevelFilter_hpp */
