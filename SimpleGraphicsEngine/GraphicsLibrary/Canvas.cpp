#include "Canvas.h"

IntPoint2D	Canvas::canvasToScreen(IntPoint2D point)
{
	point.x = this->width / 2 + point.x;
	point.y = this->height / 2 - point.y;
	return point;
}