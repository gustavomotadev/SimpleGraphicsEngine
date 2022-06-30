#include "Canvas.h"

Canvas::Canvas(unsigned int width, unsigned int height)
{
	this->width = width;
	this->height = height;
}

Canvas::IntPoint2D	Canvas::canvasToScreen(Canvas::IntPoint2D point)
{
	point.x = (this->width / 2) + point.x;
	point.y = (this->height / 2) - point.y;
	return point;
}

Canvas::IntPoint2D Canvas::screenToCanvas(Canvas::IntPoint2D point)
{
	point.x = point.x - (this->width / 2);
	point.y = (this->height / 2) - point.y;
	return point;
}

unsigned int Canvas::getWidth()
{
	return this->width;
}

unsigned int Canvas::getHeight()
{
	return this->height;
}