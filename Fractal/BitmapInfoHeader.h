// Name: BitmapInfoHeader.h

#ifndef _BITMAPINFOHEADER_H_
#define _BITMAPINFOHEADER_H_

#include <cstdint>

using namespace std;

#pragma pack(2)

namespace bitmap{
struct BitmapInfoHeader {
    int32_t headerSize{40};
    int32_t width;
    int32_t height;
    int16_t planes{1};
    int16_t bitsPerPixel{24};
    int32_t compression{0};
    int32_t dataSize{0};
    int32_t horizontalResolution{2400};
    int32_t varticalResolution{2400};
    int32_t colors{0x22222222};
    int32_t importantColors{0};  
};
}; // namespace bitmap

#endif // _BITMAPINFOHEADER_H_ 