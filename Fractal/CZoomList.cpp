// Name : CZoomList.cpp

#include "CZoomList.h"
#include "CZoom.h"

CZoomList::CZoomList()
{
    
};

CZoomList::CZoomList(int width, int height): m_width(width), m_height(height)
{
    
};

void CZoomList::add(const CZoom& zoom)
{
    zooms.push_back(zoom);

    m_xCenter += (zoom.x - m_width/2)* m_scale;
    m_yCenter += -(zoom.y - m_height/2)* m_scale;

    m_scale *= zoom.scale;
}

std::pair<double, double> CZoomList::doZoom(int x, int y)
{
    double xFractal = (x - m_width/2)*m_scale + m_xCenter;
    double yFractal = (y - m_height/2)*m_scale + m_yCenter;

    std::pair<double, double> ret{xFractal, yFractal}; 
    return ret;
}