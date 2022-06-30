#include "Viewport.h"

Viewport::Viewport(float width, float height, float z, Canvas& viewportCanvas) : 
	canvas(viewportCanvas)
{
	this->width = width;
	this->height = height;
	this->z = z;
}

Math::Vector2D Viewport::viewportToCanvas(Math::Vector3D point)
{
	return Math::Vector2D {
		point.x * (this->canvas.getWidth() / this->width), 
		point.y* (this->canvas.getHeight() / this->height)};
}

Math::Vector3D Viewport::canvasToViewport(Math::Vector2D point)
{
	return Math::Vector3D{
		point.x*(this->width / this->canvas.getWidth()),
		point.y*(this->height / this->canvas.getHeight()),
		this->z};
}