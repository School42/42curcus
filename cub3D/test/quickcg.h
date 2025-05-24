#ifndef QUICKCG_H
#define QUICKCG_H

#include <SDL/SDL.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

namespace QuickCG
{
    // Color structure
    struct ColorRGB
    {
        int r, g, b;
        
        ColorRGB(int red = 0, int green = 0, int blue = 0) : r(red), g(green), b(blue) {}
        
        // Operator for dimming colors (used for side walls)
        ColorRGB operator/(int divisor) const
        {
            return ColorRGB(r / divisor, g / divisor, b / divisor);
        }
    };

    // Predefined colors
    extern const ColorRGB RGB_Red;
    extern const ColorRGB RGB_Green;
    extern const ColorRGB RGB_Blue;
    extern const ColorRGB RGB_White;
    extern const ColorRGB RGB_Yellow;
    extern const ColorRGB RGB_Black;

    // Global variables
    extern SDL_Surface* surface;
    extern int w, h;
    extern bool running;
    extern Uint8* keys;

    // Core functions
    void screen(int width, int height, int fullscreen, const std::string& title);
    bool done();
    void redraw();
    void cls();
    void print(double value);
    double getTicks();
    void readKeys();
    bool keyDown(SDLKey key);

    // Drawing functions
    void pset(int x, int y, const ColorRGB& color);
    void verLine(int x, int y1, int y2, const ColorRGB& color);
    void horLine(int y, int x1, int x2, const ColorRGB& color);
    void line(int x1, int y1, int x2, int y2, const ColorRGB& color);
    void rect(int x1, int y1, int x2, int y2, const ColorRGB& color);
    void rectFill(int x1, int y1, int x2, int y2, const ColorRGB& color);

    // Utility functions
    Uint32 colorToUint32(const ColorRGB& color);
    void sleep(int milliseconds);
}

#endif // QUICKCG_H