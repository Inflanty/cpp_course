// Name : CZoomList.h

#ifndef _CZOOMLIST_H_
#define _CZOOMLIST_H_

#include <vector>
#include <utility>
#include "CZoom.h"

class CZoomList{
private:
double m_xCenter{0};
double m_yCenter{0};
double m_scale{1.0};

int m_width{0};
int m_height{0};
std::vector<CZoom> zooms;

public:
CZoomList();
CZoomList(int width, int height);
void add(const CZoom& zoom);
std::pair<double, double> doZoom(int x, int y);
};

#endif // _CZOOMLIST_H_