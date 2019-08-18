// Name: Fractal.cpp
// build command: gcc -std=c++14 CZoomList.cpp CBitmap.cpp CMandelbrot.cpp CFractalCreator.cpp CRGB.cpp Fractal.cpp -o Fractal -lstdc++ -lm

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
#include "CRGB.h"

// #define USE_STEP_CODE
#define USE_FRACTAL_CREATOR

using namespace std;
using namespace bitmap;

int const WIDTH = 1920;
int const HEIGHT = 1080;


int main(){

    CRGB rgb1(4, 5, 6);
    CRGB rgb2(3, 4, 5);

    CRGB rgb3 = rgb1 - rgb2;

    cout << rgb3.r << " " << rgb3.g << " " << rgb3.b << endl;

#ifdef USE_FRACTAL_CREATOR
    auto startCreator = std::chrono::system_clock::now();
    std::time_t start_time_creator = std::chrono::system_clock::to_time_t(startCreator);
    std::cout << "Started computation at " << std::ctime(&start_time_creator);


    CFractalCreator FractalTest(WIDTH, HEIGHT);

    FractalTest.addRange(0.0, CRGB(0, 0, 0));
    FractalTest.addRange(0.3, CRGB(255, 0, 0));
    FractalTest.addRange(0.5, CRGB(255, 255, 0));
    FractalTest.addRange(1.0, CRGB(255, 255, 255));

    cout << FractalTest.getRange(999) << endl;

    // FractalTest.addZoom(CZoom((295/800)*WIDTH, (302/600)*HEIGHT, 0.1));
    // FractalTest.addZoom(CZoom(0.5*WIDTH, HEIGHT, 0.69));
    FractalTest.buildFractal("NewFractal.bmp");
    

    auto endCreator = std::chrono::system_clock::now();
    if(1)
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
