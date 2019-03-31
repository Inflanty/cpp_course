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
#define DOMAIN_COORIZATION

using namespace std;
using namespace bitmap;

bool tryFractal(void);

int const WIDTH = 1920;
int const HEIGHT = 1080;


int main(){
    CBitmap Bitmap(WIDTH, HEIGHT);
    
    complex<double> NullPx(0.0, 0.0);
    CMandelbrot Mandelbrot(NullPx);

    CHSL PixelColorHSL(0, 0, 0);
    CRGB PixelColorRGB(0, 0, 0);

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
    #ifdef DOMAIN_COORIZATION
    for( int y = 0; y < (HEIGHT); y ++ )
    {
        for( int x = 0; x < (WIDTH); x ++ )
        {
            vector<uint8_t> pixelColor = Mandelbrot.getDoubleIterationsDOMAIN(x, y);
            // cout << static_cast<unsigned>(pixelColor[0]) << ", " << static_cast<unsigned>(pixelColor[1]) << ", "  << static_cast<unsigned>(pixelColor[2]) << endl;
            Bitmap.setPixel(x, y, static_cast<unsigned>(pixelColor[0]), pixelColor[1], pixelColor[2]);
        }
    }
    #endif // DOMAIN_COORIZATION
    
    bool result = Bitmap.write("test.bmp");
    
    auto end = std::chrono::system_clock::now();

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
    // cout << "Output values : " << PixelColorRGB.R << ", " << PixelColorRGB.G << ", " << PixelColorRGB.B << endl;  static_cast<unsigned>
    return 0; 
}
