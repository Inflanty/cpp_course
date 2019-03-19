// Name: CMandelbrot.h

#ifndef _CMANDELBROT_H_
#define _CMANDELBROT_H_

#include <complex>
#include <vector>

using namespace std;

class CMandelbrot{
private:
static const int MAX_ITERATIONS{10000};
int const WIDTH{1920};
int const HEIGHT{1080};

complex<double> MandelbrotResultBase;
complex<double> MandelbrotResult;
complex<double> pixelFactor;

public:
CMandelbrot(complex<double> arg_PixelNull);
virtual ~CMandelbrot(void);

int getDoubleIterations(double x, double y);
int getDoubleIterationsUSER(int x, int y);
complex<double> getDoubleIterationsCOMPLEX(int x, int y);
vector<double> domainColorization(complex<double> singlePixel, int iteration);
void doSomethingFun(complex<double> singlePixel);

};

#endif //_CMANDELBROT_H_