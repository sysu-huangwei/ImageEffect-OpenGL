//
//  BackgroundLineFilter.hpp
//
//  Created by rayyyhuang on 2021/6/11.
//

#ifndef BackgroundLineFilter_hpp
#define BackgroundLineFilter_hpp

#include "FilterChain.hpp"
#include "BaseDefine.h"

namespace effect {

/// 画背景+线格的滤镜
class BackgroundLineFilter : public FilterChain {
public:
    
    BackgroundLineFilter();
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_BackgroundLine; }
    
    /// 设置需要画的线【此接口和render并行调用会有线程问题，需要保证先后顺序】
    /// @param lines 线信息，需要归一化到0到1的点
    virtual void setLines(std::vector<BaseLine> lines);
    
};

}

#endif /* BackgroundLineFilter_hpp */
