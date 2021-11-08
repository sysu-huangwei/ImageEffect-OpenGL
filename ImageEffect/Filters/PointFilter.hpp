//
//  PointFilter.hpp
//
//  Created by rayyyhuang on 2021/4/16.
//

#ifndef PointFilter_hpp
#define PointFilter_hpp

#include <vector>
#include "BaseFilter.hpp"
#include "BaseDefine.h"

namespace effect {

/// 画点的滤镜
class PointFilter : public BaseFilter {
public:
    ~PointFilter();
    
    /// 滤镜的类型
    std::string filterType() override { return FilterType_Point; }
    
    /// 初始化，必须在GL线程，子类实现这个方法去做GL相关的初始化操作
    virtual void init() override;
    
    /// 渲染，必须在GL线程
    /// @param outputFrameBuffer 目标FBO
    virtual void renderToFrameBuffer(std::shared_ptr<FrameBuffer> outputFrameBuffer) override;
    
    /// 设置需要画的点，内部会做拷贝【此接口和render并行调用会有线程问题，需要保证先后顺序】
    /// @param points 点位信息，需要归一化到0到1的点
    virtual void setPoints(std::vector<BasePoint> points);
    
protected:
    float *points = nullptr;
    int pointsCount = 0;
    
    /// 在最终渲染之前判断是否需要渲染
    virtual bool isNeedRender() override;
};

}

#endif /* PointFilter_hpp */
