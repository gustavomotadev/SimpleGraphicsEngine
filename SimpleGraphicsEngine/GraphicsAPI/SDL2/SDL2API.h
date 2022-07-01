#pragma once

#include "../GraphicsAPI.h"
#include <string>
#include "SDL.h"
#include <cstdint>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <iostream>

class SDL2API : public GraphicsAPI
{
	protected:
		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;
		SDL_Texture* texture = NULL;
		SDL_Surface* surface = NULL;
		uint8_t * frameBuffer = NULL;
		unsigned int frameBufferSize = 0;
		SDL_Event windowEvent = SDL_Event();
		uint32_t lastFrameTime = 0;

	public:
		SDL2API(unsigned int winWidth, unsigned int winHeight,
			unsigned int targetFPS);
		~SDL2API();
		bool init() override;
		void clearWindow() override;
		void drawPoint(unsigned int x, unsigned int y,
			uint8_t r, uint8_t g, uint8_t b) override;
		void updateScreen() override;
		bool loopOnce(bool update = true) override;
		void freeResources() override;
};