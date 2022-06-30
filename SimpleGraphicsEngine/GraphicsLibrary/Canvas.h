#pragma once

class Canvas
{
	protected:
		unsigned int width;
		unsigned int height;

	public:

		struct IntPoint2D
		{
			int x;
			int y;
		};

		Canvas(unsigned int width, unsigned int height);
		IntPoint2D canvasToScreen(IntPoint2D point);
		IntPoint2D screenToCanvas(IntPoint2D point);
		unsigned int getWidth();
		unsigned int getHeight();
};