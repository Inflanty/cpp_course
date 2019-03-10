// Name: CBitmap.cpp

#include "CBitmap.h"

#include <fstream>
#include <cstdint>
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace bitmap;
using namespace std;

namespace bitmap{
CBitmap::CBitmap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]{})
{

}

void CBitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{

}

bool CBitmap::write(string filename)
{ 
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;
    
    fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + (m_width*m_height*3);
    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

    infoHeader.width = m_width;
    infoHeader.height = m_height;

    fstream file;
    file.open(filename, fstream::out|fstream::binary);
    if(file)
    {
        return false;
    }

    file.write((char *)&fileHeader, sizeof(fileHeader));
    file.write((char *)&infoHeader, sizeof(infoHeader));
    file.write((char *)m_pPixels.get(), m_width*m_height*3);

    file.close();
    if(file)
    {
        return false;
    }
    
    return true;
}

CBitmap::~CBitmap()
{
    
}
}