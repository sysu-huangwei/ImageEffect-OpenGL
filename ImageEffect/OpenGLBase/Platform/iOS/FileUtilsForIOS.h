//
//  FileUtilsForIOS.h
//
//  Created by rayyyhuang on 2021/4/14.
//

const char *getResourcePathForIOS();

unsigned char *loadMemoryToRGBAPixelsForIOS(const char *memoryData, unsigned long dataSize, int &outWidth, int &outHeight);

void readTextureToUIImage(int textureID, int width, int height);

void readFrameBufferToUIImage(int frameBufferID, int width, int height);
