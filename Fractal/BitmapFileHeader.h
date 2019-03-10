// Name: BitmapFileHeader.h

#ifndef _BITMAPFILEHEADER_H_
#define _BITMAPFILEHEADER_H_

#include <cstdint>

using namespace std;

#pragma pack(2)

namespace bitmap{
struct BitmapFileHeader {
    char header[2]{'B', 'M'};
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset;
};
};// namespace bitmap

#endif // _BITMAPFILEHEADER_H_