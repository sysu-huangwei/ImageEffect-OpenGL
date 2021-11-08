//
//  BackgroundPointFilter.cpp
//
//  Created by rayyyhuang on 2021/6/15.
//

#include "BackgroundPointFilter.hpp"
#include "PointFilter.hpp"

namespace effect {

BackgroundPointFilter::BackgroundPointFilter() {
    FilterNodeDescription begin = defaultBeginNodeDescription;
    begin.nextIDs.push_back("copy");
    begin.nextTextureIndices.push_back(0);
    begin.nextIDs.push_back("point");
    begin.nextTextureIndices.push_back(0);
    
    FilterNodeDescription copy;
    copy.id = "copy";
    copy.filterDesc.type = FilterType_Copy;
    
    FilterNodeDescription point;
    point.id = "point";
    point.filterDesc.type = FilterType_Point;
    
    nodeDescriptions.push_back(begin);
    nodeDescriptions.push_back(copy);
    nodeDescriptions.push_back(point);
}

void BackgroundPointFilter::setPoints(std::vector<BasePoint> points) {
    std::shared_ptr<PointFilter> pointFilter = std::static_pointer_cast<PointFilter>(getFilterByNodeID("point"));
    if (pointFilter) {
        pointFilter->setPoints(points);
    }
}

}
