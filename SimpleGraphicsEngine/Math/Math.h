#pragma once

#include <cstdint>

class Math
{
public:

	struct BarycentricWeights
	{
		float w1;
		float w2;
		float w3;
	};

	static uint8_t uint8ClampF(float value);
	static uint8_t uint8ClampU(unsigned int value);
	static float zeroToUnitClampF(float value);
	static float lerpPercentF(float v0, float v1, float percent);
	static int lerpPercentI(int v0, int v1, float percent);
	static float lerpF(float x0, float y0, float x1, float y1, float x);
	static int lerpI(int x0, int y0, int x1, int y1, int x);
	static float blerpPercentF(float v00, float v01, float v10, float v11, 
		float percentX, float percentY);
	static int blerpPercentI(int v00, int v01, int v10, int v11, 
		float percentX, float percentY);
	static Math::BarycentricWeights barycentric(int x1, int y1, int x2, int y2, 
		int x3, int y3, int x, int y);
	static bool isInsideTriangle(Math::BarycentricWeights weights);
};