// SimpleGraphicsEngine.cpp : Defines the entry point for the application.
//

#include "SimpleGraphicsEngine.h"

void testDrawing(GraphicsAPI* api)
{
    RGB8BitColor c1 = RGB8BitColor(255, 0, 255);
    RGB8BitColor c2 = RGB8BitColor(255, 255, 0);
    RGB8BitColor c3 = RGB8BitColor(0, 0, 0);

    api->clearWindow(0, 0, 0);
    for (unsigned int x = 0; x < api->getWindowWidth(); x++)
    {
        c3 = RGB8BitColor::interpolate(c1, c2, (float)x / (api->getWindowWidth() - 1));
        for (unsigned int j = api->getWindowHeight()*0.45; j < api->getWindowHeight()*0.55; j++)
        {
            api->drawPoint(x, j, c3.getR(), c3.getG(), c3.getB());
        }
    }
}

int main(int argc, char* argv[])
{
    SDL2API api = SDL2API(640, 640, 60);

    api.init();

    api.setWindowTitle("Simple Graphics Engine");

    api.clearWindow(0, 0, 0);

    api.setDrawingCallback(testDrawing);

    while (api.loopOnce());

    api.freeResources();

    return 0;
}
