// Name: CMandelbrot.h

#ifndef _CMANDELBROT_H_
#define _CMANDELBROT_H_

#include <complex>

using namespace std;

class CMandelbrot{
private:
static const int MAX_ITERATIONS{255};
int const WIDTH{800};
int const HEIGHT{600};

complex<double> MandelbrotResultBase;
complex<double> MandelbrotResult;
complex<double> pixelFactor;

public:
CMandelbrot(complex<double> arg_PixelNull);
virtual ~CMandelbrot(void);

int getDoubleIterations(double x, double y);
int getDoubleIterationsUSER(int x, int y);
void doSomethingFun(complex<double> singlePixel);

};

#endif //_CMANDELBROT_H_