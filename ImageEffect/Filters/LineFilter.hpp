//
//  LineFilter.hpp
//
//  Created by rayyyhuang on 2021/4/20.
//

#ifndef LineFilter_hpp
#define LineFilter_hpp

#include "BaseFilter.hpp"
#include <vector>
#include "BaseDefine.h"

namespace effect {

/// 画线的滤镜
class LineFilter : public BaseFilter {
public:
    ~LineFilter();
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_Line; }
    
    /// 初始化，必须在GL线程，子类实现这个方法去做GL相关的初始化操作
    virtual void init() override;
    
    /// 渲染，必须在GL线程
    /// @param outputFrameBuffer 目标FBO
    virtual void renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) override;
    
    /// 设置需要画的线【此接口和render并行调用会有线程问题，需要保证先后顺序】
    /// @param lines 线信息，需要归一化到0到1的点
    virtual void setLines(std::vector<BaseLine> lines);
    
protected:
    float *lines = nullptr;
    int linesCount = 0;
    
    /// 在最终渲染之前判断是否需要渲染
    virtual bool isNeedRender() override;
};

}

#endif /* LineFilter_hpp */
