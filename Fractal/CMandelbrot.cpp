// Name: CMandelbrot.cpp

#include "CMandelbrot.h"

#include <complex>
#include <iostream>
#include <vector>

using namespace std;

CMandelbrot::CMandelbrot(complex<double> arg_PixelNull): MandelbrotResultBase(0.0, 0.0), MandelbrotResult(arg_PixelNull), pixelFactor(arg_PixelNull)
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

    return 0;
}

int CMandelbrot::getDoubleIterationsUSER(int x, int y)
{
    double xFractal = (x - WIDTH/2)* 4.0/WIDTH;
    double yFractal = (y - HEIGHT/2)* 4.0/HEIGHT;
    pixelFactor.real(xFractal);
    pixelFactor.imag(yFractal);
    MandelbrotResultBase.real(0);
    MandelbrotResultBase.imag(0);
    int iteration = 0;

    do
    {
        MandelbrotResult = pow(MandelbrotResultBase, 2) + pixelFactor;
        MandelbrotResultBase = MandelbrotResult;
        iteration ++;
    } while ((abs<double>(MandelbrotResult) <= 2.0) && (iteration <= MAX_ITERATIONS));

    return (iteration-1);
}

complex<double> CMandelbrot::getDoubleIterationsCOMPLEX(int x, int y)
{
    double xFractal = (x - WIDTH/2)* 8.0/WIDTH;
    double yFractal = (y - HEIGHT/2)* 8.0/HEIGHT;
    pixelFactor.real(xFractal);
    pixelFactor.imag(yFractal);
    MandelbrotResultBase.real(0);
    MandelbrotResultBase.imag(0);
    int iteration = 0;

    do
    {
        MandelbrotResult = pow(MandelbrotResultBase, 2) + pixelFactor;
        MandelbrotResultBase = MandelbrotResult;
        iteration ++;
    } while ((abs<double>(MandelbrotResult) <= 2.0) && (iteration <= MAX_ITERATIONS));

    return MandelbrotResult;
}

vector<double> CMandelbrot::domainColorization(complex<double> singlePixel, int iteration)
{
    double hue = arg(singlePixel);
    double saturation = abs(singlePixel);
    double lightness = 1;

    if ( iteration > MAX_ITERATIONS )
    {
        lightness = 0;
    }
    
    vector<double> HSL{hue, saturation, lightness};
    return HSL;   
}

void CMandelbrot::doSomethingFun(complex<double> singlePixel)
{
    if((abs<double>(singlePixel)) > 2.0)
    {
        // TODO: do something fun
        cout << "PIXEL : (" << (double)singlePixel.real() << ", " << (double)singlePixel.imag() << ")" << "\nHas Complex magnitude < 2" << endl; 

    }
}

/*
###COLORS TABLE###
-1 : 	(0, 255, 255)
0:      (0, 0, 0)
1:      (255, 0, 0)

-1i :   (0, 255, 0)
0i :    (0 , 0, 0)
1i:     (255, 0, 255)

*/