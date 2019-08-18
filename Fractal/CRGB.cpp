// Name : CRGB.cpp

#include "CRGB.h"

CRGB::CRGB(double r, double g, double b) : r(r), g(g), b(b)
{

}

CRGB operator-(const CRGB& first, const CRGB& second)
{
    return CRGB(first.r - second.r, first.g - second.g, first.b - second.b);
}