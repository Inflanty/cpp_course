// Name: Fractal.cpp
// build command: gcc -std=c++14 CBitmap.cpp Fractal.cpp -o Fractal -lstdc++

#include <iostream>
#include "CBitmap.h"

using namespace std;
using namespace bitmap;

int main(){
    int const WEIGHT = 800;
    int const HEIGHT = 600;
    CBitmap Bitmap(WEIGHT, HEIGHT);

    Bitmap.setColor(174, 0, 116);
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