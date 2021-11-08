//
//  BlurFilter.hpp
//
//  Created by rayyyhuang on 2021/8/16.
//

#ifndef BlurFilter_hpp
#define BlurFilter_hpp

#define DEFAULT_MAX_LENGTH 180

#include "FilterChain.hpp"

namespace effect {

/// 模糊封装
class BlurFilter : public FilterChain {
public:
    
    BlurFilter();
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_Blur; }
    
    /// 设置绘制尺寸
    /// @param outputWidth 宽
    /// @param outputHeight 高
    virtual void setOutputSize(int outputWidth, int outputHeight) override;
    
    
protected:
    
    /// 对宽高进行缩放，把短边控制在最大maxLength内
    /// @param width 宽，输入和输出
    /// @param height  高，输入和输出
    /// @param maxLength 短边最大的长度
    void scaleWH(int &width, int &height, int maxLength = DEFAULT_MAX_LENGTH);
    
    /// 在最终渲染之前判断是否需要渲染
    virtual bool isNeedRender() override { return true; }
};

}

#endif /* BlurFilter_hpp */
