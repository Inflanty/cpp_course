// Name : CFractalCreator.cpp

#include <iostream>
#include <math.h>
#include <utility>
#include <complex>

#include "CBitmap.h"
#include "CFractalCreator.h"
#include "CZoomList.h"
#include "CZoom.h"
#include "CMandelbrot.h"

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
}

void CFractalCreator::drawFractal()
{
    calculateIterations();
    calculateTotalIterations();
    
    for (int y = 0; y < m_height; y ++)
    {
        for (int x = 0; x < m_width; x ++)
        {
            uint8_t red = 0, green = 0, blue = 0;

            int iterations = fractal[y * m_width + x];

            if(iterations != MAX_ITERATIONS)
            {
                double hue = 0.0;

                for (int i = 0; i <= iterations; i++)
                {
                    hue += ((double)histogram[i])/m_total;
                }

                red = (40  *  hue);
                green = (240  *  hue);
                blue = (255  *  hue);
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