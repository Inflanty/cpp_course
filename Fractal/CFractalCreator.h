// Name : CFractalCreator.h

#ifndef _FRACTALCREATOR_H_
#define _FRACTALCREATOR_H_

#include <string>
#include <utility>

#include "CBitmap.h"
#include "CMandelbrot.h"
#include "CZoomList.h"
#include "CZoom.h"

using namespace bitmap;

class CFractalCreator {
public:
static const int MAX_ITERATIONS{100};
int const WIDTH{1920};
int const HEIGHT{1080};

private:
int m_width;
int m_height;
int m_total;

CBitmap m_bitmap;
CZoomList m_zoomList;
CMandelbrot m_mandlebrot;

unique_ptr<int[]> fractal;
unique_ptr<int[]> histogram;

public:
CFractalCreator(const int width, const int height);
virtual ~CFractalCreator();

static int getIterations(double x, double y);
void calculateIterations();
void calculateTotalIterations();
void drawFractal();
void addZoom(const CZoom& zoom);
bool writeBitmap(std::string name);
};

#endif // _FRACTALCREATOR_H_