#include <cstdint>
#include "Math.h"

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
		static RGB8BitColor interpolate(RGB8BitColor start, RGB8BitColor end, float point);
		uint8_t getR();
		uint8_t getG();
		uint8_t getB();
};