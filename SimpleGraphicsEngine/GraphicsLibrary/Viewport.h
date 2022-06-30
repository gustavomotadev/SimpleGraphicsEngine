#pragma once

#include "Canvas.h"
#include "../Math/Math.h"

class Viewport
{
	protected:
		float width;
		float height;
		float z;
		Canvas& canvas;

	public:
		Viewport(float width, float height, float z, Canvas& viewportCanvas);
		Math::Vector2D viewportToCanvas(Math::Vector3D point);
		Math::Vector3D canvasToViewport(Math::Vector2D point);
};