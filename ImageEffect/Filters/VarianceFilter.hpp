//
//  VarianceFilter.hpp
//
//  Created by rayyy on 2022/4/1.
//

#ifndef VarianceFilter_hpp
#define VarianceFilter_hpp

#include "FilterChain.hpp"

namespace effect {

/// 方差
class VarianceFilter : public FilterChain {
public:
    
    VarianceFilter();
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_Variance; }
    
protected:
    
    /// 在最终渲染之前判断是否需要渲染
    virtual bool isNeedRender() override { return true; }
};

}

#endif /* VarianceFilter_hpp */
