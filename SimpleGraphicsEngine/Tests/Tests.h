#pragma once

#include "../GraphicsAPI/GraphicsAPI.h"
#include "../GraphicsLibrary/RGB8BitColor.h"
#include "../Math/Math.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

class Tests
{
	public:
		static void seedRandom();
		static void gradients(GraphicsAPI& api);
		static void movingGradient(GraphicsAPI& api);
		static void bigGradient(GraphicsAPI& api);
};