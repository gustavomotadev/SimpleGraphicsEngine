#include "RGB8BitColor.h"

RGB8BitColor::RGB8BitColor(uint8_t r, uint8_t g, uint8_t b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

RGB8BitColor RGB8BitColor::operator * (const float& k)
{
	return RGB8BitColor(Math::uint8ClampF(this->r * k), 
		Math::uint8ClampF(this->g * k), 
		Math::uint8ClampF(this->b * k));
}

RGB8BitColor operator * (float k, const RGB8BitColor& c)
{
	return RGB8BitColor(Math::uint8ClampF(c.r * k), 
		Math::uint8ClampF(c.g * k), 
		Math::uint8ClampF(c.b * k));
}

RGB8BitColor RGB8BitColor::operator + (const RGB8BitColor& c)
{
	return RGB8BitColor(Math::uint8ClampU((unsigned int) this->r + c.r), 
		Math::uint8ClampU((unsigned int) this->g + c.g),
		Math::uint8ClampU((unsigned int) this->b + c.b));
}

RGB8BitColor RGB8BitColor::linearInterpolation(
	RGB8BitColor start, RGB8BitColor end, float percent)
{
	percent = Math::zeroToUnitClampF(percent);
	return RGB8BitColor((uint8_t) Math::lerpPercentI(start.r, end.r, percent),
		(uint8_t) Math::lerpPercentI(start.g, end.g, percent),
		(uint8_t) Math::lerpPercentI(start.b, end.b, percent));
}

RGB8BitColor RGB8BitColor::bilinearInterpolation(
	RGB8BitColor c00, RGB8BitColor c01,
	RGB8BitColor c10, RGB8BitColor c11, float percentX, float percentY)
{
	percentX = Math::zeroToUnitClampF(percentX);
	percentY = Math::zeroToUnitClampF(percentY);
	return RGB8BitColor((uint8_t) Math::blerpPercentI(
		c00.r, c01.r, c10.r, c11.r, percentX, percentY),
		(uint8_t) Math::blerpPercentI(
		c00.g, c01.g, c10.g, c11.g, percentX, percentY),
		(uint8_t) Math::blerpPercentI(
		c00.b, c01.b, c10.b, c11.b, percentX, percentY));
}

RGB8BitColor RGB8BitColor::randomNiceColor()
{
	switch (rand()%6)
	{
		case 0:
			return RGB8BitColor(255, rand()%255, 0);
			break;
		case 1:
			return RGB8BitColor(rand()%255, 255, 0);
			break;
		case 2:
			return RGB8BitColor(0, 255, rand()%255);
			break;
		case 3:
			return RGB8BitColor(0, rand()%255, 255);
			break;
		case 4:
			return RGB8BitColor(rand()%255, 0, 255);
			break;
		case 5:
			return RGB8BitColor(255, 0, rand()%255);
			break;
	}
}

uint8_t RGB8BitColor::getR() { return this->r; }
uint8_t RGB8BitColor::getG() { return this->g; }
uint8_t RGB8BitColor::getB() { return this->b; }