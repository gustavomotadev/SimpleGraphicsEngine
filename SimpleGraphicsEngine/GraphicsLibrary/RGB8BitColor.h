#pragma once

#include <cstdint>
#include "../Math/Math.h"

class RGB8BitColor
{
	protected:
		uint8_t r;
		uint8_t g;
		uint8_t b;

	public:
		RGB8BitColor(uint8_t r, uint8_t g, uint8_t b);
		RGB8BitColor operator * (const float &k);
		friend RGB8BitColor operator * (float k, const RGB8BitColor& c);
		RGB8BitColor operator + (const RGB8BitColor& c);
		static RGB8BitColor linearInterpolation(
			RGB8BitColor start, RGB8BitColor end, float percent);
		static RGB8BitColor bilinearInterpolation(
			RGB8BitColor c00, RGB8BitColor c01, 
			RGB8BitColor c10, RGB8BitColor c11, float percentX, float percentY);
		uint8_t getR();
		uint8_t getG();
		uint8_t getB();
};