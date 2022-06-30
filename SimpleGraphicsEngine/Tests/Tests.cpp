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
        t.p1.x = rand() % api.getWindowWidth();
        t.p1.y = rand() % api.getWindowHeight();
        t.p2.x = rand() % api.getWindowWidth();
        t.p2.y = rand() % api.getWindowHeight();
        t.p3.x = rand() % api.getWindowWidth();
        t.p3.y = rand() % api.getWindowHeight();
        t = Math::order(t);

        tNext.p1.x = rand() % api.getWindowWidth();
        tNext.p1.y = rand() % api.getWindowHeight();
        tNext.p2.x = rand() % api.getWindowWidth();
        tNext.p2.y = rand() % api.getWindowHeight();
        tNext.p3.x = rand() % api.getWindowWidth();
        tNext.p3.y = rand() % api.getWindowHeight();
        tNext = Math::order(tNext);

        firstRun = false;
    }

    api.clearWindow(0, 0, 0);

    for (int x = t.p2.x; x <= t.p3.x; x++)
    {
        for (int y = t.p1.y; y <= t.p2.y; y++)
        {
            weights = Math::barycentric(t.p1.x, t.p1.y, t.p2.x, t.p2.y, t.p3.x, t.p3.y, x, y);
            if (Math::isInsideTriangle(weights))
            {
                cd = (weights.w1 * ca) + (weights.w2 * cb) + (weights.w3 * cc);
                api.drawPoint(x, y, cd.getR(), cd.getG(), cd.getB());
            }
        }
    }

    percent += 0.0007;
    t.p1.x = Math::lerpPercentI(t.p1.x, tNext.p1.x, percent);
    t.p1.y = Math::lerpPercentI(t.p1.y, tNext.p1.y, percent);
    t.p2.x = Math::lerpPercentI(t.p2.x, tNext.p2.x, percent);
    t.p2.y = Math::lerpPercentI(t.p2.y, tNext.p2.y, percent);
    t.p3.x = Math::lerpPercentI(t.p3.x, tNext.p3.x, percent);
    t.p3.y = Math::lerpPercentI(t.p3.y, tNext.p3.y, percent);
    t = Math::order(t);

    ca = RGB8BitColor::linearInterpolation(ca, na, percent);
    cb = RGB8BitColor::linearInterpolation(cb, nb, percent);
    cc = RGB8BitColor::linearInterpolation(cc, nc, percent);

    if (percent >= 0.07)
    {
        percent = 0;

        tNext.p1.x = rand() % api.getWindowWidth();
        tNext.p1.y = rand() % api.getWindowHeight();
        tNext.p2.x = rand() % api.getWindowWidth();
        tNext.p2.y = rand() % api.getWindowHeight();
        tNext.p3.x = rand() % api.getWindowWidth();
        tNext.p3.y = rand() % api.getWindowHeight();
        tNext = Math::order(tNext);

        na = RGB8BitColor::randomNiceColor();
        nb = RGB8BitColor::randomNiceColor();
        nc = RGB8BitColor::randomNiceColor();
    }
}