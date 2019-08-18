// Name : CFractalCreator.h

#ifndef _FRACTALCREATOR_H_
#define _FRACTALCREATOR_H_

#include <string>
#include <utility>
#include <vector>

#include "CBitmap.h"
#include "CMandelbrot.h"
#include "CZoomList.h"
#include "CZoom.h"
#include "CRGB.h"

using namespace bitmap;

class CFractalCreator {
public:
static const int MAX_ITERATIONS{1000};
int const WIDTH{1920};
int const HEIGHT{1080};

private:
int m_width;
int m_height;
int m_total;

bool m_bGotFirstRange{false};

CBitmap m_bitmap;
CZoomList m_zoomList;
CMandelbrot m_mandlebrot;

unique_ptr<int[]> fractal;
unique_ptr<int[]> histogram;

std::vector<int> m_ranges;
std::vector<CRGB> m_colors;
std::vector<int> m_rangesTotals;

static int getIterations(double x, double y);
void calculateIterations();
void calculateTotalIterations();
void calculateRangeTotals();
void drawFractal();
bool writeBitmap(std::string name);

public:
CFractalCreator(const int width, const int height);
virtual ~CFractalCreator();
void addRange(double rangeEnd, const CRGB& rgb);
void addZoom(const CZoom& zoom);
void buildFractal(std::string name);
int getRange(int iterations) const;
};

#endif // _FRACTALCREATOR_H_