// SimpleGraphicsEngine.cpp : Defines the entry point for the application.
//

#include "SimpleGraphicsEngine.h"

void testDrawing(GraphicsAPI* api)
{
    api->clearWindow(0, 0, 0);
    for (unsigned int x = 0; x < api->getWindowWidth(); x++)
    {
        api->drawPoint(x, x, 255, 0, 0);
        api->drawPoint(api->getWindowWidth()-x, x, 255, 255, 0);
    }
}

int main(int argc, char* argv[])
{
    SDL2API api = SDL2API(480, 480, 60);

    api.init();

    api.setWindowTitle("Simple Graphics Engine");

    api.clearWindow(0, 0, 0);

    api.setDrawingCallback(testDrawing);

    while (api.loopOnce());

    api.freeResources();

    return 0;
}
