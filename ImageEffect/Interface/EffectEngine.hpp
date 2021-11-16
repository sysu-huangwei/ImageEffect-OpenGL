//
//  EffectEngine.hpp
//
//  Created by rayyy on 2021/11/9.
//

#ifndef EffectEngine_hpp
#define EffectEngine_hpp

#include "FilterChain.hpp"

namespace effect {

/// 效果引擎接口
class EffectEngine : public FilterChain {
public:
    
    EffectEngine(std::vector<FilterNodeDescription> nodeDescriptions);
    
    /// 滤镜的类型
    std::string filterType() override { return "EffectEngine"; }
};

}

#endif /* EffectEngine_hpp */
