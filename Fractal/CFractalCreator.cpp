// Name : CFractalCreator.cpp

#include <iostream>
#include <math.h>
#include <utility>
#include <complex>
#include <cassert>

#include "CBitmap.h"
#include "CFractalCreator.h"
#include "CZoomList.h"
#include "CZoom.h"
#include "CMandelbrot.h"
#include "CRGB.h"

using namespace bitmap;
using namespace std;

CFractalCreator::CFractalCreator(const int width, const int height): 
    m_total(0),
    m_width(width), 
    m_height(height), 
    fractal(new int[width*height]{ 0 }), 
    histogram(new int[MAX_ITERATIONS]{ 0 }), 
    m_bitmap(width, height),
    m_zoomList(width, height),
    m_mandlebrot()
{
    m_zoomList.add(CZoom(m_width/2, m_height/2, 4.0/m_width));
}

CFractalCreator::~CFractalCreator()
{

}

void CFractalCreator::buildFractal(std::string name)
{
    calculateIterations();
    calculateTotalIterations();
    calculateRangeTotals();
    drawFractal();
    
    bool resultCreator = writeBitmap(name);
    (void) resultCreator;

}

void CFractalCreator::addRange(double rangeEnd, const CRGB& rgb)
{
    m_ranges.push_back(rangeEnd*MAX_ITERATIONS);
    m_colors.push_back(rgb);

    if(m_bGotFirstRange)
    {
        m_rangesTotals.push_back(0);
    }
    m_bGotFirstRange = true;
    
}

void CFractalCreator::calculateRangeTotals()
{
    int rangeIndex = 0;

    for(int i = 0; i < MAX_ITERATIONS; i++)
    {
        int pixels = histogram[i];  

        if(i >= m_ranges[rangeIndex+1])
        {
            rangeIndex ++;
        }

        m_rangesTotals[rangeIndex] += pixels;
    }

    int overallTotal = 0;

    for(int value: m_rangesTotals)
    {
        std::cout << "Range total : " << value << std::endl;
        overallTotal += value;
    }

    std::cout << "Overall total 1 : " << overallTotal << std::endl;
}

int CFractalCreator::getIterations(double x, double y)
{
    complex<double> z = 0;
    complex<double> c(x, y);

    int iterations = 0;

    while(iterations < MAX_ITERATIONS){
        z = z*z + c;

        if(abs(z) > 2)
        {
            break;
        }
        iterations ++;
    }
    
    return iterations;
}

void CFractalCreator::calculateIterations()
{
    for (int y = 0; y < m_height; y ++)
    {
        for (int x = 0; x < m_width; x ++)
        {
            std::pair<double, double> cords = m_zoomList.doZoom(x, y);
            int iterations = getIterations(cords.first, cords.second);
            fractal[y*m_width+x] = iterations;
            if(iterations != MAX_ITERATIONS)
            {
                histogram[iterations]++;
            }
        }
    }
}

void CFractalCreator::calculateTotalIterations()
{
    for (int i = 0; i < MAX_ITERATIONS; i ++)
    {
        m_total += histogram[i]; 
    }

    std::cout << "Overall total 2 : " << m_total << std::endl;
}

void CFractalCreator::drawFractal()
{
    CRGB startColor(0, 0, 0);
    CRGB endColor(0, 0, 255);
    CRGB colorDiff = endColor - startColor;
    
    for (int y = 0; y < m_height; y ++)
    {
        for (int x = 0; x < m_width; x ++)
        {
            int iterations = fractal[y * m_width + x];
            
            int range = getRange(iterations);
            int rangeTotal = m_rangesTotals[range];
            int rangeStart = m_ranges[range];

            CRGB& satartColor = m_colors[range];
            CRGB& endColor = m_colors[range + 1];
            CRGB colorDiff = endColor - startColor;

            uint8_t red = 0, green = 0, blue = 0;

            if(iterations != MAX_ITERATIONS)
            {
                int totalPixels = 0;

                for (int i = rangeStart; i <= iterations; i++)
                {
                    totalPixels += histogram[i];
                }

                red = startColor.r + colorDiff.r*(double)totalPixels/rangeTotal;
                green = startColor.g + colorDiff.g*(double)totalPixels/rangeTotal;
                blue = startColor.b + colorDiff.b*(double)totalPixels/rangeTotal;
            }
            m_bitmap.setPixel(x, y, red, green, blue);
        }
    }
}

void CFractalCreator::addZoom(const CZoom& zoom)
{
    m_zoomList.add(zoom);
}

bool CFractalCreator::writeBitmap(std::string name)
{
    m_bitmap.write(name);
    return 1;
}

int CFractalCreator::getRange(int iterations) const
{
    int range = 0;

    for(int i = 1; i < m_ranges.size(); i ++)
    {
        range = i;

        if(m_ranges[i] > iterations)
        {
            break;
        }
    }
        range --;

        assert(range > -1);
        assert(range < m_ranges.size());

        return range;
}