#include "Math.h"

uint8_t Math::uint8ClampF(float value)
{
	if (value < 0) return 0;
	if (value > 255) return 255;
	return (uint8_t) value;
}

uint8_t Math::uint8ClampU(unsigned int value)
{
	if (value < 0) return 0;
	if (value > 255) return 255;
	return (uint8_t) value;
}

float Math::zeroToUnitClampF(float value)
{
	if (value < 0) return 0;
	if (value > 1) return 1;
	return value;
}