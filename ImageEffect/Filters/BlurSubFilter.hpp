//
//  BlurSubFilter.hpp
//
//  Created by rayyyhuang on 2021/8/17.
//

#ifndef BlurSubFilter_hpp
#define BlurSubFilter_hpp

#include "BaseFilter.hpp"

namespace effect {

/// 模糊
class BlurSubFilter : public BaseFilter {
public:
    
    enum BlurDirection {
        BlurDirection_Horizontal,
        BlurDirection_Vertical
    };
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_BlurSub; }
    
    /// 初始化，必须在GL线程，子类实现这个方法去做GL相关的初始化操作
    virtual void init() override;
    
    /// 设置绘制尺寸
    /// @param outputWidth 宽
    /// @param outputHeight 高
    virtual void setOutputSize(int outputWidth, int outputHeight) override;
    
    /// 渲染，必须在GL线程
    /// @param outputFrameBuffer 目标FBO
    virtual void renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) override;
    
    /// 设置参数
    /// @param param 参数
    virtual void setParams(const std::map<std::string, std::string> &param) override;
    
    
protected:
    
    BlurDirection direction = BlurDirection_Horizontal;
    float widthOffset = 0.0f, heightOffset = 0.0f;
};

}

#endif /* BlurSubFilter_hpp */
