#include "Tests.h"

void Tests::gradients(GraphicsAPI* api)
{
    api->clearWindow(0, 0, 0);

    RGB8BitColor c1 = RGB8BitColor(0, 0, 0);
    RGB8BitColor c2 = RGB8BitColor(255, 255, 255);
    RGB8BitColor c3 = RGB8BitColor(0, 0, 0);

    for (unsigned int x = 0; x < api->getWindowWidth(); x++)
    {
        c3 = RGB8BitColor::linearInterpolation(c1, c2, (float)x / (api->getWindowWidth() - 1));
        for (unsigned int j = api->getWindowHeight() * 0.15; j < api->getWindowHeight() * 0.30; j++)
        {
            api->drawPoint(x, j, c3.getR(), c3.getG(), c3.getB());
        }
    }

    RGB8BitColor c00 = RGB8BitColor(255, 0, 0);
    RGB8BitColor c01 = RGB8BitColor(0, 255, 0);
    RGB8BitColor c10 = RGB8BitColor(255, 255, 0);
    RGB8BitColor c11 = RGB8BitColor(0, 0, 255);
    RGB8BitColor cxx = RGB8BitColor(0, 0, 0);

    unsigned int x0 = api->getWindowWidth() * 0.15;
    unsigned int y0 = api->getWindowHeight() * 0.45;
    unsigned int w = api->getWindowWidth() * 0.30;

    for (unsigned int x = x0; x < x0 + w; x++)
    {
        for (unsigned int y = y0; y < y0 + w; y++)
        {
            cxx = RGB8BitColor::bilinearInterpolation(
                c00, c01, c10, c11, (float)(x - x0) / w, (float)(y - y0) / w);
            api->drawPoint(x, y, cxx.getR(), cxx.getG(), cxx.getB());
        }
    }

    RGB8BitColor ca = RGB8BitColor(0, 255, 255);
    RGB8BitColor cb = RGB8BitColor(255, 0, 255);
    RGB8BitColor cc = RGB8BitColor(255, 255, 0);
    RGB8BitColor cd = RGB8BitColor(0, 0, 0);

    unsigned int x1 = api->getWindowWidth() * 0.70;
    unsigned int y1 = api->getWindowHeight() * 0.45;
    unsigned int x2 = api->getWindowWidth() * 0.55;
    unsigned int y2 = api->getWindowHeight() * 0.75;
    unsigned int x3 = api->getWindowWidth() * 0.85;
    unsigned int y3 = api->getWindowHeight() * 0.75;

    Math::BarycentricWeights weights;

    for (unsigned int x = x2; x <= x3; x++)
    {
        for (unsigned int y = y1; y <= y2; y++)
        {
            weights = Math::barycentric(x1, y1, x2, y2, x3, y3, x, y);
            if (Math::isInsideTriangle(weights))
            {
                cd = (weights.w1 * ca) + (weights.w2 * cb) + (weights.w3 * cc);
                api->drawPoint(x, y, cd.getR(), cd.getG(), cd.getB());
            }
        }
    }
}