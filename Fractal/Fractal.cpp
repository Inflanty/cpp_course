// Name: Fractal.cpp
// build command: gcc -std=c++14 CBitmap.cpp CMandelbrot.cpp Fractal.cpp -o Fractal -lstdc++ -lm

// Fractals introduction [PL] : https://rst.software/blog/2018/01/30/fraktale-ukryte-piekno-matematyki/

#include <iostream>
#include "CBitmap.h"
#include "CMandelbrot.h"

using namespace std;
using namespace bitmap;

bool tryFractal(void);

int const WIDTH = 1920;
int const HEIGHT = 1080;

int main(){
    CBitmap Bitmap(WIDTH, HEIGHT);
    
    complex<double> NullPx(0.0, 0.0);
    CMandelbrot Mandelbrot(NullPx);

    for( int y = 0; y < HEIGHT; y ++ )
    {
        for( int x = 0; x < WIDTH; x ++ )
        {
            int SinglePixelColor = Mandelbrot.getDoubleIterationsUSER(x, y);
            Bitmap.setPixel(x, y, SinglePixelColor/128, 0, (SinglePixelColor/2));
            cout << "PixelColor = " << SinglePixelColor << endl;
        }
    }

    bool result = Bitmap.write("test.bmp");
    if(result)
    {
        cout << "FINISH" << endl;
    }
    else
    {
        cout << "ERROR" << endl;
    }
    
    return 0;
}

bool iteratePixels(void)
{
    for( int y = 0; y < HEIGHT; y ++ )
    {
        for( int x = 0; x < WIDTH; x ++ )
        {

        }
    }
}