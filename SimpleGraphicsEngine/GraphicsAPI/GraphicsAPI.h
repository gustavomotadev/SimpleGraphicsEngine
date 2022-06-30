#pragma once

#include <string>
#include <functional>

class GraphicsAPI
{
	protected:
		unsigned int windowWidth;
		unsigned int windowHeight;
		std::string windowTitle;
		unsigned int targetFPS;
		bool freed = false;
		std::function<void(GraphicsAPI&)> drawingCallback;

	public:

		GraphicsAPI(unsigned int winWidth, unsigned int winHeight,
			unsigned int targetFPS);
		~GraphicsAPI();
		void setDrawingCallback(void (*callback)(GraphicsAPI&));
		void setTargetFPS(unsigned int target);
		void setWindowTitle(std::string title);
		unsigned int getWindowWidth();
		unsigned int getWindowHeight();
		virtual bool init() = 0;
		virtual void clearWindow(uint8_t r, uint8_t g, uint8_t b) = 0;
		virtual void drawPoint(unsigned int x, unsigned int y, 
			uint8_t r, uint8_t g, uint8_t b) = 0;
		virtual void updateScreen() = 0;
		virtual bool loopOnce(bool update=true) = 0;
		virtual void freeResources() = 0;
};