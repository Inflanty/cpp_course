// Name: CBitmap.h

#ifndef _BITMAP_H_
#define _BITMAP_H_

#include <string>
#include <cstdint>
#include <memory>

using namespace std;

namespace bitmap{
class CBitmap{
private:
    int m_width{0};
    int m_height{0};
    unique_ptr<uint8_t[]> m_pPixels{nullptr};
    

public:
    CBitmap();
    CBitmap(int width, int height);
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    void setColor(uint8_t red, uint8_t green, uint8_t blue);
    bool write(string filename);
    virtual ~CBitmap();

    int const WIDTH{1920};
    int const HEIGHT{1080};
};
}// namespace bitmap

#endif // _BITMAP_H_