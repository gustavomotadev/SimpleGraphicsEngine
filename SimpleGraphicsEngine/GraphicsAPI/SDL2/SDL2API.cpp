#include "SDL2API.h"

SDL2API::SDL2API(unsigned int winWidth, unsigned int winHeight,
	unsigned int targetFPS) : 
	GraphicsAPI(winWidth, winHeight, targetFPS)
{

}

SDL2API::~SDL2API()
{
    this->freeResources();
}

bool SDL2API::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) return false;

    this->window = SDL_CreateWindow(this->windowTitle.c_str(), 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        this->windowWidth, this->windowHeight, SDL_WINDOW_SHOWN);
    if (this->window == NULL) return false;

    this->surface = SDL_GetWindowSurface(this->window);
    this->frameBufferSize = 4 * this->getWindowWidth() * this->getWindowHeight();
    this->frameBuffer = (uint8_t *) this->surface->pixels;
    std::cout << SDL_GetPixelFormatName(this->surface->format->format) << std::endl;

    this->lastFrameTime = SDL_GetTicks();

    return true;
}

void SDL2API::clearWindow()
{
    std::memset(this->frameBuffer, 0, this->frameBufferSize);
}

void SDL2API::drawPoint(unsigned int x, unsigned int y,
    uint8_t r, uint8_t g, uint8_t b)
{
    if (x < this->getWindowWidth() &&
        y < this->getWindowHeight())
    {
        //ASSUMING PIXEL FORMAT IS SDL_PIXELFORMAT_RGB888
        //THAT IS 32BIT WITH MASK BGRX
        unsigned int pos = 4 * y * this->getWindowWidth() + 4 * x;
        this->frameBuffer[pos] = b;
        this->frameBuffer[pos + 1] = g;
        this->frameBuffer[pos + 2] = r;
    }
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

    if (this->drawingCallback) this->drawingCallback(*this);

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
    SDL_FreeSurface(this->surface);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}