// Name: CMandelbrot.cpp

#include "CMandelbrot.h"

#include <iostream>
#include <complex>

using namespace std;

CMandelbrot::CMandelbrot(void)
{

}

CMandelbrot::~CMandelbrot(void)
{

}

int CMandelbrot::getIterations(double x, double y)
{   
    complex<double> z = 0;
    complex<double> c(x, y);

    int iterations = 0;

    while(iterations < MAX_ITERATIONS){
        z = z*z + c;

        if(abs(z) > 2)
        {
            break;
        }
        iterations ++;
    }
    
    return iterations;
}
