//
//  SmoothFilter.hpp
//
//  Created by Ray on 2021/8/22.
//

#ifndef SmoothFilter_hpp
#define SmoothFilter_hpp

#include "FilterChain.hpp"

namespace effect {

/// 模糊
class SmoothFilter : public FilterChain {
public:
    
    SmoothFilter();
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_Smooth; }
    
    /// 设置参数
    /// @param param 参数
    virtual void setParams(const std::map<std::string, std::string> &param) override;
    
};

}

#endif /* SSmoothFilter_hpp */
