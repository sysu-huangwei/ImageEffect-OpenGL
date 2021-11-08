//
//  BackgroundPointFilter.hpp
//
//  Created by rayyyhuang on 2021/6/15.
//

#ifndef BackgroundPointFilter_hpp
#define BackgroundPointFilter_hpp

#include "FilterChain.hpp"
#include "BaseDefine.h"

namespace effect {

/// 画背景+点的滤镜
class BackgroundPointFilter : public FilterChain {
public:
    
    BackgroundPointFilter();
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_BackgroundPoint; }
    
    /// 设置需要画的点，内部会做拷贝【此接口和render并行调用会有线程问题，需要保证先后顺序】
    /// @param points 点位信息，需要归一化到0到1的点
    virtual void setPoints(std::vector<BasePoint> points);
    
};

}

#endif /* BackgroundPointFilter_hpp */
