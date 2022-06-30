#include "Viewport.h"

Viewport::Viewport(float width, float height, Canvas& viewportCanvas) : canvas(viewportCanvas)
{
	this->width = width;
	this->height = height;
}

Canvas::IntPoint2D Viewport::viewportToCanvas(Viewport::FloatPoint2D point)
{
	point.x = point.x* (this->canvas.getWidth() / this->width);
	point.y = point.y * (this->canvas.getHeight() / this->height);

	return Canvas::IntPoint2D {(int) point.x, (int) point.y};
}

Viewport::FloatPoint2D Viewport::canvasToViewport(Canvas::IntPoint2D point)
{
	return Viewport::FloatPoint2D{
		point.x*(this->width / this->canvas.getWidth()),
		point.y*(this->height / this->canvas.getHeight())};
}