#pragma once

#include "../Math/Math.h"

class Canvas
{
	protected:
		unsigned int width;
		unsigned int height;

	public:
		Canvas(unsigned int width, unsigned int height);
		Math::Vector2D canvasToScreen(Math::Vector2D point);
		Math::Vector2D screenToCanvas(Math::Vector2D point);
		unsigned int getWidth();
		unsigned int getHeight();
};