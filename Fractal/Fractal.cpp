// Name: Fractal.cpp
// build command: gcc -std=c++14 CColorConverter.cpp CBitmap.cpp CMandelbrot.cpp Fractal.cpp -o Fractal -lstdc++ -lm

// Fractals introduction [PL] : https://rst.software/blog/2018/01/30/fraktale-ukryte-piekno-matematyki/

#include <iostream>
#include <chrono>
#include <ctime>
#include "CBitmap.h"
#include "CMandelbrot.h"
#include "CColorConverter.h"

// #define USER_ITERATION
// #define COMPLEX_ITERATION

using namespace std;
using namespace bitmap;

bool tryFractal(void);

int const WIDTH = 1920;
int const HEIGHT = 1080;

int main(){
    CBitmap Bitmap(WIDTH, HEIGHT);
    
    complex<double> NullPx(0.0, 0.0);
    CMandelbrot Mandelbrot(NullPx);

    auto start = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
    std::cout << "Started computation at " << std::ctime(&start_time);
    #ifdef USER_ITERATION
    for( int y = 0; y < HEIGHT; y ++ )
    {
        for( int x = 0; x < WIDTH; x ++ )
        {
            int SinglePixelColor = Mandelbrot.getDoubleIterationsUSER(x, y);
            if(SinglePixelColor > 256)
            {
                Bitmap.setPixel(x, y, 0, 0, 255);    
            }
            Bitmap.setPixel(x, y, SinglePixelColor/128, 0, (SinglePixelColor/2));
            
        }
    }
    #endif // USER_ITERATION
    #ifdef COMPLEX_ITERATION
    for( int y = 0; y < HEIGHT; y ++ )
    {
        for( int x = 0; x < WIDTH; x ++ )
        {
            complex<double> SinglePixelColor = Mandelbrot.getDoubleIterationsCOMPLEX(x, y);
            cout << "PIXEL : " << x << "x" << y << " -> " << SinglePixelColor.real() << ", " << SinglePixelColor.imag() << endl;
        }
    }
    #endif // COMPLEX_ITERATION
    
    auto end = std::chrono::system_clock::now();
    bool result = Bitmap.write("test.bmp");

    if(result)
    {
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);

        std::cout << "finished computation at " << std::ctime(&end_time)
                  << "elapsed time: " << elapsed_seconds.count() << "s\n";
    }
    else
    {
        cout << "ERROR" << endl;
    }

    CHSL test( 180, 1, 0.2);
    CRGB testRGB(0, 0, 0);

    testRGB = HSLToRGB(test);

    cout << "Output values : " << static_cast<unsigned>(testRGB.R) << ", " << static_cast<unsigned>(testRGB.G) << ", " << static_cast<unsigned>(testRGB.B) << endl;

    return 0;
}
