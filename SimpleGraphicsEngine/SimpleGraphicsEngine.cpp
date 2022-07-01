#include "SimpleGraphicsEngine.h"

int main(int argc, char* argv[])
{
    SDL2API api = SDL2API(1600, 900, 60);

    api.init();

    api.setWindowTitle("SGE");

    api.clearWindow();

    Tests::seedRandom();
    api.setDrawingCallback(Tests::bigGradient);

    while (api.loopOnce());

    api.freeResources();

    return 0;
}
