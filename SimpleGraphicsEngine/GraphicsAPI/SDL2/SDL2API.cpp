#include "SDL2API.h"

SDL2API::SDL2API(unsigned int winWidth, unsigned int winHeight,
	unsigned int targetFPS) : 
	GraphicsAPI(winWidth, winHeight, targetFPS)
{

}

SDL2API::~SDL2API()
{

}

bool SDL2API::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) return false;

    this->window = SDL_CreateWindow(this->windowTitle.c_str(), 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        this->windowWidth, this->windowHeight, SDL_WINDOW_SHOWN);
    if (this->window == NULL) return false;

    this->windowSurface = SDL_GetWindowSurface(this->window);
    if (this->windowSurface == NULL) return false;

    this->softwareRenderer = SDL_CreateSoftwareRenderer(this->windowSurface);
    if (this->softwareRenderer == NULL) return false;

    this->lastFrameTime = SDL_GetTicks();

    return true;
}

void SDL2API::clearWindow(uint8_t r, uint8_t g, uint8_t b)
{
    SDL_SetRenderDrawColor(this->softwareRenderer, 
        r, g, b, SDL_ALPHA_OPAQUE);

    SDL_RenderClear(this->softwareRenderer);
}

void SDL2API::drawPoint(unsigned int x, unsigned int y,
    uint8_t r, uint8_t g, uint8_t b)
{
    SDL_SetRenderDrawColor(this->softwareRenderer,
        r, g, b, SDL_ALPHA_OPAQUE);

    SDL_RenderDrawPoint(this->softwareRenderer, x, y);
}

void SDL2API::updateScreen()
{
    SDL_UpdateWindowSurface(this->window);
}

bool SDL2API::loopOnce(bool update)
{
    bool returnValue = true;

    while (SDL_PollEvent(&this->windowEvent)) {
        if (windowEvent.type == SDL_QUIT) {
            returnValue = false;
        }
    }

    if (this->drawingCallback != NULL) this->drawingCallback(this);

    if (this->targetFPS > 0)
    {
        float delay = ((((float) 1000.0 / this->targetFPS)) - (SDL_GetTicks() - this->lastFrameTime));
        if (delay > 0) SDL_Delay((uint32_t) delay);
    }

    if (update)
    {
        uint32_t now;
        float fps;

        this->updateScreen();

        now = SDL_GetTicks();
        fps = (float) 1000.0 / (now - this->lastFrameTime);
        this->lastFrameTime = now;

        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << fps;
        SDL_SetWindowTitle(this->window, (this->windowTitle + " (FPS: " + stream.str() + ")").c_str());
    }

    return returnValue;
}

void SDL2API::freeResources()
{
    SDL_DestroyRenderer(this->softwareRenderer);
    SDL_FreeSurface(this->windowSurface);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}