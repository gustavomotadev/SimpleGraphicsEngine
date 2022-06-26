#include "GraphicsAPI.h"

GraphicsAPI::GraphicsAPI(unsigned int winWidth, unsigned int winHeight,
	unsigned int targetFPS)
{
	this->windowWidth = winWidth;
	this->windowHeight = winHeight;
	this->targetFPS = targetFPS;
}

GraphicsAPI::~GraphicsAPI()
{

}

void GraphicsAPI::setDrawingCallback(void (*callback)(GraphicsAPI*))
{
	this->drawingCallback = callback;
}

void GraphicsAPI::setTargetFPS(unsigned int target)
{
	this->targetFPS = target;
}

void GraphicsAPI::setWindowTitle(std::string title)
{
	this->windowTitle = title;
}

unsigned int GraphicsAPI::getWindowWidth()
{
	return this->windowWidth;
}

unsigned int GraphicsAPI::getWindowHeight()
{
	return this->windowHeight;
}