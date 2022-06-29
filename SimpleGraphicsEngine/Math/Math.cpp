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

float Math::lerpPercentF(float v0, float v1, float percent)
{
	return v0 + ((v1 - v0) * percent);
}

int Math::lerpPercentI(int v0, int v1, float percent) {
	return (int) (v0 + ((v1 - v0) * percent));
}

float Math::lerpF(float x0, float y0, float x1, float y1, float x) 
{
	return y0 + (((y1 - y0) / (x1 - x0)) * (x - x0));
}

int Math::lerpI(int x0, int y0, int x1, int y1, int x)
{
	return y0 + (((y1 - y0) / (x1 - x0)) * (x - x0));
}

int Math::blerpPercentI(int v00, int v01, int v10, int v11, 
	float percentX, float percentY)
{
	return lerpPercentI(lerpPercentI(v00, v10, percentX), 
		lerpPercentI(v01, v11, percentX), percentY);
}

float Math::blerpPercentF(float v00, float v01, float v10, float v11, 
	float percentX, float percentY)
{
	return lerpPercentF(lerpPercentF(v00, v10, percentX), 
		lerpPercentF(v01, v11, percentX), percentY);
}

Math::BarycentricWeights Math::barycentric(int x1, int y1, int x2, int y2,
	int x3, int y3, int x, int y)
{
	int x3MinusX2 = x3 - x2;
	int x1MinusX3 = x1 - x3;
	int y2MinusY3 = y2 - y3;
	int xMinusX3 = x - x3;
	int yMinusY3 = y - y3;
	int denominator = (y2MinusY3 * x1MinusX3) + (x3MinusX2 * (y1 - y3));

	Math::BarycentricWeights weights;

	weights.w1 = ((y2MinusY3 * xMinusX3) + (x3MinusX2 * yMinusY3)) / (float) denominator;
	weights.w2 = (((y3 - y1) * xMinusX3) + (x1MinusX3 * yMinusY3)) / (float) denominator;
	weights.w3 = 1 - weights.w1 - weights.w2;
	
	return weights;
}

bool Math::isInsideTriangle(Math::BarycentricWeights weights)
{
	if (weights.w1 < 0 || weights.w2 < 0 || weights.w3 < 0) return false;
	else return true;
}