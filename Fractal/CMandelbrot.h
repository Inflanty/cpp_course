// Name: CMandelbrot.h

#ifndef _CMANDELBROT_H_
#define _CMANDELBROT_H_

using namespace std;

class CMandelbrot{
public:
static const int MAX_ITERATIONS{100};
int const WIDTH{1920};
int const HEIGHT{1080};

public:
CMandelbrot(void);
virtual ~CMandelbrot(void);
static int getIterations(double x, double y);
};

#endif //_CMANDELBROT_H_