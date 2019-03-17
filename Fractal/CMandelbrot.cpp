// Name: CMandelbrot.cpp

#include "CMandelbrot.h"

#include <complex>
#include <iostream>

using namespace std;

CMandelbrot::CMandelbrot(complex<double> arg_PixelNull): MandelbrotResultBase.real(0), MandelbrotResultBase.imag(0), MandelbrotResult(arg_PixelNull), pixelFactor(arg_PixelNull)
{

}

CMandelbrot::~CMandelbrot(void)
{

}

int CMandelbrot::getDoubleIterations(double x, double y)
{   
    double min = 99999;
    double max = -99999;
    
    for( int y = 0; y < HEIGHT; (y + 1) )
    {
        for( int x = 0; x < WIDTH; (x + 1) )
        {
            double xFractal = (x - WIDTH/2) * 2.0/WIDTH;
            double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;
            if( xFractal < min ) min = xFractal;
            if( xFractal > max ) max = xFractal;
        }
    }

    return 1;
}

int CMandelbrot::getDoubleIterationsUSER(int x, int y)
{
    pixelFactor.real(x);
    pixelFactor.imag(y);
    int iteration = 0;

    do
    {
        MandelbrotResult = pow(MandelbrotResultBase, 2) + pixelFactor;
        MandelbrotResultBase = MandelbrotResult;
        iteration ++;
    } while ((abs<double>(MandelbrotResult) <= 2.0) && (iteration <= MAX_ITERATIONS));

    return iteration;
}

void CMandelbrot::doSomethingFun(complex<double> singlePixel)
{
    if((abs<double>(singlePixel)) > 2.0)
    {
        // TODO: do something fun
        cout << "PIXEL : (" << (double)singlePixel.real() << ", " << (double)singlePixel.imag() << ")" << "\nHas Complex magnitude < 2" << endl; 

    }
}