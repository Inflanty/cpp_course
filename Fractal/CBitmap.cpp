// Name: CBitmap.cpp

#include "CBitmap.h"

#include <fstream>
#include <cstdint>
#include <iostream>
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace bitmap;
using namespace std;

namespace bitmap{
CBitmap::CBitmap()
{
    
}

CBitmap::CBitmap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]{})
{

}

void CBitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
    uint8_t *pPixel = m_pPixels.get();
    pPixel += (y*3)*m_width+(x*3);
    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;
}

void CBitmap::setColor(uint8_t red, uint8_t green, uint8_t blue)
{
    for( int y = 0; y < m_height; y ++ )
    {
        for( int i = 0; i < m_width; i ++ )
        {
            uint8_t *pPixel = m_pPixels.get();
            pPixel += (y*3)*m_width+(i*3);
            pPixel[0] = blue;
            pPixel[1] = green;
            pPixel[2] = red;
        }
    }
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
    file.open(filename, ios::out | ios::binary);
    if(!file)
    {
        return false;
    }

    file.write((char *)&fileHeader, sizeof(fileHeader));
    file.write((char *)&infoHeader, sizeof(infoHeader));
    file.write((char *)m_pPixels.get(), m_width*m_height*3);

    file.close();
    if(!file)
    {
        return false;
    }
    
    return true;
}

CBitmap::~CBitmap()
{
    
}
}