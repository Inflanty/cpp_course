// Name: Fractal.cpp
// build command: gcc -std=c++14 CZoomList.cpp CBitmap.cpp CMandelbrot.cpp CFractalCreator.cpp Fractal.cpp -o Fractal -lstdc++ -lm

// Fractals introduction [PL] : https://rst.software/blog/2018/01/30/fraktale-ukryte-piekno-matematyki/

#include <iostream>
#include <chrono>
#include <ctime>
#include <memory>
#include <math.h>
#include <utility>
#include "CBitmap.h"
#include "CMandelbrot.h"
#include "CZoomList.h"
#include "CZoom.h"
#include "CFractalCreator.h"

// #define USE_STEP_CODE
#define USE_FRACTAL_CREATOR

using namespace std;
using namespace bitmap;

bool tryFractal(void);

int const WIDTH = 1920;
int const HEIGHT = 1080;


int main(){
    
#ifdef USE_STEP_CODE
    auto start = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
    std::cout << "Started computation at " << std::ctime(&start_time);
    
    CBitmap Bitmap(WIDTH, HEIGHT);
    double min = 99999;
    double max = -99999;


    CZoomList zoomList(WIDTH, HEIGHT);

    zoomList.add(CZoom(WIDTH/2 , HEIGHT/2, 4.0/WIDTH));
    zoomList.add(CZoom(WIDTH/2 , HEIGHT/2, 2.0/WIDTH));

    unique_ptr<int[]> histogram(new int[CMandelbrot::MAX_ITERATIONS]{});
    unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{ 0 });

    for (int y = 0; y < HEIGHT; y ++)
    {
        for (int x = 0; x < WIDTH; x ++)
        {
            std::pair<double, double> cords = zoomList.doZoom(x, y);

            int iterations = CMandelbrot::getIterations(cords.first, cords.second);

            fractal[y*WIDTH+x] = iterations;

            if(iterations != CMandelbrot::MAX_ITERATIONS)
            {
                histogram[iterations]++;
            }
        }
    }

    int total = 0;
    for (int i = 0; i < CMandelbrot::MAX_ITERATIONS; i ++)
    {
        total += histogram[i];
    }
    
    for (int y = 0; y < HEIGHT; y ++)
    {
        for (int x = 0; x < WIDTH; x ++)
        {
            uint8_t red = 0, green = 0, blue = 0;

            int iterations = fractal[y * WIDTH + x];

            if(iterations != CMandelbrot::MAX_ITERATIONS)
            {
                double hue = 0.0;

                for (int i = 0; i <= iterations; i++)
                {
                    hue += ((double)histogram[i])/total;
                }

                red =   hue * 20;
                green = hue * 240;
                blue =  hue * 255;
            }
            Bitmap.setPixel(x, y, red, green, blue);
        }
    }
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
#endif
#ifdef USE_FRACTAL_CREATOR
    auto startCreator = std::chrono::system_clock::now();
    std::time_t start_time_creator = std::chrono::system_clock::to_time_t(startCreator);
    std::cout << "Started computation at " << std::ctime(&start_time_creator);

    CFractalCreator FractalTest(WIDTH, HEIGHT);
    
    FractalTest.drawFractal();
    bool resultCreator = FractalTest.writeBitmap("TestFractal.bmp");
    auto endCreator = std::chrono::system_clock::now();

    if(resultCreator)
    {
        std::chrono::duration<double> elapsed_seconds = endCreator-startCreator;
        std::time_t end_time_creator = std::chrono::system_clock::to_time_t(endCreator);

        std::cout << "finished computation at " << std::ctime(&end_time_creator)
                  << "elapsed time: " << elapsed_seconds.count() << "s\n";
    }
    else
    {
        cout << "ERROR" << endl;
    }

#endif
    return 0; 
}
