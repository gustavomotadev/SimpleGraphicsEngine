#include "Tests.h"

void Tests::seedRandom()
{
    srand(time(NULL));
}

void Tests::gradients(GraphicsAPI& api)
{
    api.clearWindow(0, 0, 0);

    RGB8BitColor c1 = RGB8BitColor(0, 0, 0);
    RGB8BitColor c2 = RGB8BitColor(255, 255, 255);
    RGB8BitColor c3 = RGB8BitColor(0, 0, 0);

    for (unsigned int x = 0; x < api.getWindowWidth(); x++)
    {
        c3 = RGB8BitColor::linearInterpolation(c1, c2, (float)x / (api.getWindowWidth() - 1));
        for (unsigned int j = api.getWindowHeight() * 0.15; j < api.getWindowHeight() * 0.30; j++)
        {
            api.drawPoint(x, j, c3.getR(), c3.getG(), c3.getB());
        }
    }

    RGB8BitColor c00 = RGB8BitColor(255, 0, 0);
    RGB8BitColor c01 = RGB8BitColor(0, 255, 0);
    RGB8BitColor c10 = RGB8BitColor(255, 255, 0);
    RGB8BitColor c11 = RGB8BitColor(0, 0, 255);
    RGB8BitColor cxx = RGB8BitColor(0, 0, 0);

    unsigned int x0 = api.getWindowWidth() * 0.15;
    unsigned int y0 = api.getWindowHeight() * 0.45;
    unsigned int w = api.getWindowWidth() * 0.30;

    for (unsigned int x = x0; x < x0 + w; x++)
    {
        for (unsigned int y = y0; y < y0 + w; y++)
        {
            cxx = RGB8BitColor::bilinearInterpolation(
                c00, c01, c10, c11, (float)(x - x0) / w, (float)(y - y0) / w);
            api.drawPoint(x, y, cxx.getR(), cxx.getG(), cxx.getB());
        }
    }

    RGB8BitColor ca = RGB8BitColor(0, 255, 255);
    RGB8BitColor cb = RGB8BitColor(255, 0, 255);
    RGB8BitColor cc = RGB8BitColor(255, 255, 0);
    RGB8BitColor cd = RGB8BitColor(0, 0, 0);

    unsigned int x1 = api.getWindowWidth() * 0.70;
    unsigned int y1 = api.getWindowHeight() * 0.45;
    unsigned int x2 = api.getWindowWidth() * 0.55;
    unsigned int y2 = api.getWindowHeight() * 0.75;
    unsigned int x3 = api.getWindowWidth() * 0.85;
    unsigned int y3 = api.getWindowHeight() * 0.75;

    Math::BarycentricWeights weights;

    for (unsigned int x = x2; x <= x3; x++)
    {
        for (unsigned int y = y1; y <= y2; y++)
        {
            weights = Math::barycentric(x1, y1, x2, y2, x3, y3, x, y);
            if (Math::isInsideTriangle(weights))
            {
                cd = (weights.w1 * ca) + (weights.w2 * cb) + (weights.w3 * cc);
                api.drawPoint(x, y, cd.getR(), cd.getG(), cd.getB());
            }
        }
    }
}

void Tests::movingGradient(GraphicsAPI& api)
{
    static bool firstRun = true;
    static Math::Triangle t;
    static Math::Triangle tNext;
    static float percent = 0.0;

    static RGB8BitColor ca = RGB8BitColor(0, 255, 255);
    static RGB8BitColor cb = RGB8BitColor(255, 0, 255);
    static RGB8BitColor cc = RGB8BitColor(255, 255, 0);

    static RGB8BitColor na = RGB8BitColor::randomNiceColor();
    static RGB8BitColor nb = RGB8BitColor::randomNiceColor();
    static RGB8BitColor nc = RGB8BitColor::randomNiceColor();

    RGB8BitColor cd = RGB8BitColor(0, 0, 0);

    Math::BarycentricWeights weights;

    if (firstRun)
    {
        t.x1 = rand() % api.getWindowWidth();
        t.y1 = rand() % api.getWindowHeight();
        t.x2 = rand() % api.getWindowWidth();
        t.y2 = rand() % api.getWindowHeight();
        t.x3 = rand() % api.getWindowWidth();
        t.y3 = rand() % api.getWindowHeight();
        t = Math::order(t);

        tNext.x1 = rand() % api.getWindowWidth();
        tNext.y1 = rand() % api.getWindowHeight();
        tNext.x2 = rand() % api.getWindowWidth();
        tNext.y2 = rand() % api.getWindowHeight();
        tNext.x3 = rand() % api.getWindowWidth();
        tNext.y3 = rand() % api.getWindowHeight();
        tNext = Math::order(tNext);

        firstRun = false;
    }

    api.clearWindow(0, 0, 0);

    for (int x = t.x2; x <= t.x3; x++)
    {
        for (int y = t.y1; y <= t.y2; y++)
        {
            weights = Math::barycentric(t.x1, t.y1, t.x2, t.y2, t.x3, t.y3, x, y);
            if (Math::isInsideTriangle(weights))
            {
                cd = (weights.w1 * ca) + (weights.w2 * cb) + (weights.w3 * cc);
                api.drawPoint(x, y, cd.getR(), cd.getG(), cd.getB());
            }
        }
    }

    percent += 0.0007;
    t.x1 = Math::lerpPercentI(t.x1, tNext.x1, percent);
    t.y1 = Math::lerpPercentI(t.y1, tNext.y1, percent);
    t.x2 = Math::lerpPercentI(t.x2, tNext.x2, percent);
    t.y2 = Math::lerpPercentI(t.y2, tNext.y2, percent);
    t.x3 = Math::lerpPercentI(t.x3, tNext.x3, percent);
    t.y3 = Math::lerpPercentI(t.y3, tNext.y3, percent);
    t = Math::order(t);

    ca = RGB8BitColor::linearInterpolation(ca, na, percent);
    cb = RGB8BitColor::linearInterpolation(cb, nb, percent);
    cc = RGB8BitColor::linearInterpolation(cc, nc, percent);

    if (percent >= 0.07)
    {
        percent = 0;

        tNext.x1 = rand() % api.getWindowWidth();
        tNext.y1 = rand() % api.getWindowHeight();
        tNext.x2 = rand() % api.getWindowWidth();
        tNext.y2 = rand() % api.getWindowHeight();
        tNext.x3 = rand() % api.getWindowWidth();
        tNext.y3 = rand() % api.getWindowHeight();
        tNext = Math::order(tNext);

        na = RGB8BitColor::randomNiceColor();
        nb = RGB8BitColor::randomNiceColor();
        nc = RGB8BitColor::randomNiceColor();
    }
}