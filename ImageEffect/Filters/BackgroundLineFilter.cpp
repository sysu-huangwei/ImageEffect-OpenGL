//
//  BackgroundLineFilter.cpp
//
//  Created by rayyyhuang on 2021/6/11.
//

#include "BackgroundLineFilter.hpp"
#include "LineFilter.hpp"

namespace effect {

BackgroundLineFilter::BackgroundLineFilter() {
    FilterNodeDescription begin = defaultBeginNodeDescription;
    begin.nextIDs.push_back("copy");
    begin.nextTextureIndices.push_back(0);
    begin.nextIDs.push_back("line");
    begin.nextTextureIndices.push_back(0);
    
    FilterNodeDescription copy;
    copy.id = "copy";
    copy.filterDesc.type = FilterType_Copy;
    
    FilterNodeDescription line;
    line.id = "line";
    line.filterDesc.type = FilterType_Line;
    
    nodeDescriptions.push_back(begin);
    nodeDescriptions.push_back(copy);
    nodeDescriptions.push_back(line);
}

void BackgroundLineFilter::setLines(std::vector<BaseLine> lines) {
    std::shared_ptr<LineFilter> lineFilter = std::static_pointer_cast<LineFilter>(getFilterByNodeID("line"));
    if (lineFilter) {
        lineFilter->setLines(lines);
    }
}

}
