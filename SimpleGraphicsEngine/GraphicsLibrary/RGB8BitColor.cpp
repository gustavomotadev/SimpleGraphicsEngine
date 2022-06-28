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

RGB8BitColor RGB8BitColor::interpolate(RGB8BitColor start, RGB8BitColor end, float point)
{
	point = Math::zeroToUnitClampF(point);
	return RGB8BitColor((uint8_t)(start.r + (((int)end.r - start.r) * point)),
		(uint8_t)(start.g + (((int)end.g - start.g) * point)),
		(uint8_t)(start.b + (((int)end.b - start.b) * point)));
}

uint8_t RGB8BitColor::getR() { return this->r; }
uint8_t RGB8BitColor::getG() { return this->g; }
uint8_t RGB8BitColor::getB() { return this->b; }