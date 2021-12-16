//
//  EffectEngine.cpp
//
//  Created by rayyy on 2021/11/9.
//

#include "EffectEngine.hpp"
#include "BaseGLUtils.hpp"
#include "EffectConfigParser.hpp"
#include "BaseDefine.h"

namespace effect {

EffectEngine::EffectEngine(std::string configFilePath) {
    unsigned long dataSise;
    char *json = BaseGLUtils::loadFileToMemory(configFilePath.c_str(), dataSise);
    nodeDescriptions = EffectConfigParser::parseJsonToDescription(std::string(json));
    SAFE_DELETE_ARRAY(json);
};

void EffectEngine::setBGRASmallImageData(unsigned char *data, size_t width, size_t height, size_t bytesPerRow) {
    if (data && width > 0 && height > 0 && bytesPerRow > 0) {
        float sumB = 0.0f;
        float sumG = 0.0f;
        float sumR = 0.0f;
        float sumBrightness = 0.0f;
        float maxB = 0.0f;
        float maxG = 0.0f;
        float maxR = 0.0f;
        float maxBrightness = 0.0f;
        float minB = 255.0f;
        float minG = 255.0f;
        float minR = 255.0f;
        float minBrightness = 255.0f;
        unsigned char *pData = data;
        for (size_t h = 0; h < height; h++) {
            for (size_t w = 0; w < width; w++) {
                size_t currentIndex = h * bytesPerRow + w * 4;
                float currentB = (float)pData[currentIndex];
                float currentG = (float)pData[currentIndex + 1];
                float currentR = (float)pData[currentIndex + 2];
                float currentBrightness = (currentB + currentG + currentR) * 0.333333f;
                sumB += currentB;
                sumG += currentG;
                sumR += currentR;
                sumBrightness += currentBrightness;
                maxB = maxB < currentB ? currentB : maxB;
                maxG = maxG < currentG ? currentG : maxG;
                maxR = maxR < currentR ? currentR : maxR;
                maxBrightness = maxBrightness < currentBrightness ? currentBrightness : maxBrightness;
                minB = minB > currentB ? currentB : minB;
                minG = minG > currentG ? currentG : minG;
                minR = minR > currentR ? currentR : minR;
                minBrightness = minBrightness > currentBrightness ? currentBrightness : minBrightness;
            }
        }
        
        size_t pixelsCount = width * height * 4;
        frameColorInfo.maxR = maxR;
        frameColorInfo.maxG = maxG;
        frameColorInfo.maxB = maxB;
        frameColorInfo.maxBrightness = sumBrightness;
        frameColorInfo.minR = minR;
        frameColorInfo.minG = minG;
        frameColorInfo.minB = minB;
        frameColorInfo.minBrightness = minBrightness;
        frameColorInfo.averageR = (float)sumR / (float)pixelsCount;
        frameColorInfo.averageG = (float)sumG / (float)pixelsCount;
        frameColorInfo.averageB = (float)sumB / (float)pixelsCount;
        frameColorInfo.averageBrightness = (float)sumBrightness / (float)pixelsCount;
    }
}

float maxBrightness;
float minBrightness;
float averageBrightness;

}
