// Name: CMandelbrot.cpp

#include "CMandelbrot.h"
#include "CColorConverter.h"

#include <complex>
#include <iostream>
#include <vector>

using namespace std;

CMandelbrot::CMandelbrot(complex<double> arg_PixelNull): MandelbrotResultBase(0.0, 0.0), MandelbrotResult(arg_PixelNull), pixelFactor(arg_PixelNull), pixelResultIteration(0.0)
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

    return MandelbrotResult;
}

vector<uint8_t> CMandelbrot::getDoubleIterationsDOMAIN(int x, int y)
{
    double xFractal = (x - WIDTH/2)* 2.0/WIDTH;
    double yFractal = (y - HEIGHT/2)* 2.0/HEIGHT;
    pixelFactor.real(xFractal);
    pixelFactor.imag(yFractal);
    MandelbrotResultBase.real(0);
    MandelbrotResultBase.imag(0);
    pixelResultIteration = 0;

    do
    {
        MandelbrotResult = pow(MandelbrotResultBase, 2) + pixelFactor;
        MandelbrotResultBase = MandelbrotResult;
        pixelResultIteration ++;
    } while ((abs<double>(MandelbrotResult) <= 2.0) && (pixelResultIteration <= MAX_ITERATIONS));

    double hue = arg(MandelbrotResult);
    double saturation = abs(MandelbrotResult);
    double lightness = 0.99;

    if ( pixelResultIteration <= MAX_ITERATIONS )
    {
        lightness = pixelResultIteration/MAX_ITERATIONS;
        // cout << lightness << endl;
    }
    else if ( pixelResultIteration > MAX_ITERATIONS )
    {
        lightness = 0;
        // cout << "0" << endl;
    }

    CHSL PixelColorHSL( hue, (float)saturation, (float)lightness);
    CRGB PixelColorRGB(0, 0, 0);

    PixelColorRGB = HSLToRGB(PixelColorHSL);

    // if( PixelColorRGB.R == PixelColorRGB.G == PixelColorRGB.B == 255 )
    // {
    //     vector<uint8_t> RGB{ (uint8_t)254, (uint8_t)222, (uint8_t)252 };
    //     return RGB;
    // }
    // else
    // {
    // }
        vector<uint8_t> RGB{ (uint8_t)PixelColorRGB.R, (uint8_t)PixelColorRGB.G, (uint8_t)PixelColorRGB.B };
        return RGB;
    
// rgb(254, 222, 252)
    // cout << static_cast<unsigned>(RGB[0]) << ", " << static_cast<unsigned>(RGB[1]) << ", "  << static_cast<unsigned>(RGB[2]) << " ??? " << lightness << endl;
}

vector<uint8_t> CMandelbrot::domainColorization()
{
    double hue = arg(MandelbrotResult);
    double saturation = abs(MandelbrotResult);
    double lightness = 1;

    if ( (MAX_ITERATIONS == 100) && (pixelResultIteration < MAX_ITERATIONS) )
    {
        lightness = pixelResultIteration/100;
    }
    else if ( pixelResultIteration > MAX_ITERATIONS )
    {
        lightness = 0;
    }

    CHSL PixelColorHSL( hue, saturation, lightness);
    CRGB PixelColorRGB(0, 0, 0);

    PixelColorRGB = HSLToRGB(PixelColorHSL);

    vector<uint8_t> RGB{ (uint8_t)PixelColorRGB.R, (uint8_t)PixelColorRGB.G, (uint8_t)PixelColorRGB.B };
    cout << static_cast<unsigned>(RGB[0]) << ", " << static_cast<unsigned>(RGB[1]) << ", "  << static_cast<unsigned>(RGB[2]) << endl;
    return RGB;   
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