#include "IntPoint2D.h"

class Canvas
{
	protected:
		unsigned int width;
		unsigned int height;

	public:
		IntPoint2D canvasToScreen(IntPoint2D point);
};