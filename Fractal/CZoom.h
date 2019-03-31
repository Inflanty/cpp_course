// Name : CZoom.h

#ifndef _CZOOM_Z_
#define _CZOOM_Z_

class CZoom {
public:
int x{0};
int y{0};
double scale{0.0};

CZoom(int x, int y, double scale) : x(x), y(y), scale(scale){};

};


#endif // _CZOOM_Z_