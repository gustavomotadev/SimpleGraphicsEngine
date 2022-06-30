#include "Canvas.h"

Canvas::Canvas(unsigned int width, unsigned int height)
{
	this->width = width;
	this->height = height;
}

Math::Vector2D	Canvas::canvasToScreen(Math::Vector2D point)
{
	point.x = (this->width / 2) + point.x;
	point.y = (this->height / 2) - point.y;
	return point;
}

Math::Vector2D Canvas::screenToCanvas(Math::Vector2D point)
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