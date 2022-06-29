#include "SimpleGraphicsEngine.h"

int main(int argc, char* argv[])
{
    SDL2API api = SDL2API(640, 640, 60);

    api.init();

    api.setWindowTitle("Simple Graphics Engine");

    api.clearWindow(0, 0, 0);

    api.setDrawingCallback(Tests::gradients);

    while (api.loopOnce());

    api.freeResources();

    return 0;
}
