#include <cstdint>

class Math
{
public:
	static uint8_t uint8ClampF(float value);
	static uint8_t uint8ClampU(unsigned int value);
	static float zeroToUnitClampF(float value);
};