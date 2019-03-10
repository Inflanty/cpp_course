// Name: Fractal.cpp

#include <iostream>
#include "CBitmap.h"

using namespace std;
using namespace bitmap;

int main(){
    CBitmap Bitmap(800, 600);

    Bitmap.write("test.bmp");
    cout << "fINISH\n" << endl;


    return 0;
}