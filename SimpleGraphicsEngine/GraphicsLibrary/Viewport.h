#pragma once

#include "Canvas.h"

class Viewport
{
	protected:
		float width;
		float height;
		Canvas& canvas;

	public:

		struct FloatPoint2D
		{
			float x;
			float y;
		};

		Viewport(float width, float height, Canvas& viewportCanvas);
		Canvas::IntPoint2D viewportToCanvas(FloatPoint2D point);
		FloatPoint2D canvasToViewport(Canvas::IntPoint2D point);
};