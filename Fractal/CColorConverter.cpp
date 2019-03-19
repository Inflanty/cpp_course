// File:  CColorConverter.cpp
#include "CColorConverter.h"

CRGB::CRGB(unsigned char r, unsigned char g, unsigned char b): R(r), G(g), B(b) {};
bool CRGB::Equals(CRGB rgb) { return (R == rgb.R) && (G == rgb.G) && (B == rgb.B); };

CHSL::CHSL(int h, float s, float l): H(h), S(s), L(l) {};
bool CHSL::Equals(CHSL hsl) { return (H == hsl.H) && (S == hsl.S) && (L == hsl.L); };


float HueToRGB(float v1, float v2, float vH) {
	if (vH < 0)
		vH += 1;

	if (vH > 1)
		vH -= 1;

	if ((6 * vH) < 1)
		return (v1 + (v2 - v1) * 6 * vH);

	if ((2 * vH) < 1)
		return v2;

	if ((3 * vH) < 2)
		return (v1 + (v2 - v1) * ((2.0f / 3) - vH) * 6);

	return v1;
}

CRGB HSLToRGB(CHSL hsl) {
	unsigned char r = 0;
	unsigned char g = 0;
	unsigned char b = 0;

	if (hsl.S == 0)
	{
		r = g = b = (unsigned char)(hsl.L * 255);
	}
	else
	{
		float v1, v2;
		float hue = (float)hsl.H / 360;

		v2 = (hsl.L < 0.5) ? (hsl.L * (1 + hsl.S)) : ((hsl.L + hsl.S) - (hsl.L * hsl.S));
		v1 = 2 * hsl.L - v2;

		r = (unsigned char)(255 * HueToRGB(v1, v2, hue + (1.0f / 3)));
		g = (unsigned char)(255 * HueToRGB(v1, v2, hue));
		b = (unsigned char)(255 * HueToRGB(v1, v2, hue - (1.0f / 3)));
	}
	return CRGB(r, g, b);
}