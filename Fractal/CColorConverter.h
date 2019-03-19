// Name: CColorConverter.h

class CRGB
{
public:
	unsigned char R;
	unsigned char G;
	unsigned char B;

	CRGB(unsigned char r, unsigned char g, unsigned char b);

	bool Equals(CRGB rgb);

	const CRGB &operator=(const CRGB &other)
	{
		R = other.R;
		G = other.G;
		B = other.B;
		return *this;
	}
};

class CHSL
{
public:
	int H;
	float S;
	float L;

	CHSL(int h, float s, float l);

	bool Equals(CHSL hsl);
};

float HueToRGB(float v1, float v2, float vH);
CRGB HSLToRGB(CHSL hsl);