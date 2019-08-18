// Name : CRGB.h

#ifndef _CRGB_H_
#define _CRGB_H_

struct CRGB
{
public:
    CRGB(double r, double g, double b);
    double r;
    double g;
    double b;
};

CRGB operator-(const CRGB& first, const CRGB& second);

#endif // _CRGB_H_