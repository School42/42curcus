#include "quickcg.h"

namespace QuickCG
{
    // Predefined colors
    const ColorRGB RGB_Red(255, 0, 0);
    const ColorRGB RGB_Green(0, 255, 0);
    const ColorRGB RGB_Blue(0, 0, 255);
    const ColorRGB RGB_White(255, 255, 255);
    const ColorRGB RGB_Yellow(255, 255, 0);
    const ColorRGB RGB_Black(0, 0, 0);

    // Global variables
    SDL_Surface* surface = NULL;
    int w = 0, h = 0;
    bool running = true;
    Uint8* keys = NULL;

    void screen(int width, int height, int fullscreen, const std::string& title)
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
            return;
        }

        w = width;
        h = height;

        Uint32 flags = SDL_SWSURFACE;
        if (fullscreen) flags |= SDL_FULLSCREEN;

        surface = SDL_SetVideoMode(width, height, 32, flags);
        if (!surface)
        {
            std::cerr << "SDL video mode initialization failed: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return;
        }

        SDL_WM_SetCaption(title.c_str(), NULL);
        keys = SDL_GetKeyState(NULL);
    }

    bool done()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = false;
                }
            }
        }
        return !running;
    }

    void redraw()
    {
        SDL_Flip(surface);
    }

    void cls()
    {
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 0));
    }

    void print(double value)
    {
        // Simple FPS display in console
        static int frameCount = 0;
        frameCount++;
        if (frameCount % 60 == 0) // Print every 60 frames
        {
            std::cout << "FPS: " << value << std::endl;
        }
    }

    double getTicks()
    {
        return SDL_GetTicks();
    }

    void readKeys()
    {
        SDL_PumpEvents();
        keys = SDL_GetKeyState(NULL);
    }

    bool keyDown(SDLKey key)
    {
        return keys && keys[key];
    }

    Uint32 colorToUint32(const ColorRGB& color)
    {
        return SDL_MapRGB(surface->format, color.r, color.g, color.b);
    }

    void pset(int x, int y, const ColorRGB& color)
    {
        if (x < 0 || x >= w || y < 0 || y >= h || !surface) return;

        Uint32 pixel = colorToUint32(color);
        Uint32* pixels = (Uint32*)surface->pixels;
        pixels[y * w + x] = pixel;
    }

    void verLine(int x, int y1, int y2, const ColorRGB& color)
    {
        if (x < 0 || x >= w || !surface) return;

        if (y1 > y2) std::swap(y1, y2);
        if (y1 < 0) y1 = 0;
        if (y2 >= h) y2 = h - 1;

        Uint32 pixel = colorToUint32(color);
        Uint32* pixels = (Uint32*)surface->pixels;

        for (int y = y1; y <= y2; y++)
        {
            pixels[y * w + x] = pixel;
        }
    }

    void horLine(int y, int x1, int x2, const ColorRGB& color)
    {
        if (y < 0 || y >= h || !surface) return;

        if (x1 > x2) std::swap(x1, x2);
        if (x1 < 0) x1 = 0;
        if (x2 >= w) x2 = w - 1;

        Uint32 pixel = colorToUint32(color);
        Uint32* pixels = (Uint32*)surface->pixels;

        for (int x = x1; x <= x2; x++)
        {
            pixels[y * w + x] = pixel;
        }
    }

    void line(int x1, int y1, int x2, int y2, const ColorRGB& color)
    {
        // Bresenham's line algorithm
        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);
        int sx = (x1 < x2) ? 1 : -1;
        int sy = (y1 < y2) ? 1 : -1;
        int err = dx - dy;

        while (true)
        {
            pset(x1, y1, color);

            if (x1 == x2 && y1 == y2) break;

            int e2 = 2 * err;
            if (e2 > -dy)
            {
                err -= dy;
                x1 += sx;
            }
            if (e2 < dx)
            {
                err += dx;
                y1 += sy;
            }
        }
    }

    void rect(int x1, int y1, int x2, int y2, const ColorRGB& color)
    {
        horLine(y1, x1, x2, color);
        horLine(y2, x1, x2, color);
        verLine(x1, y1, y2, color);
        verLine(x2, y1, y2, color);
    }

    void rectFill(int x1, int y1, int x2, int y2, const ColorRGB& color)
    {
        if (x1 > x2) std::swap(x1, x2);
        if (y1 > y2) std::swap(y1, y2);

        for (int y = y1; y <= y2; y++)
        {
            horLine(y, x1, x2, color);
        }
    }

    void sleep(int milliseconds)
    {
        SDL_Delay(milliseconds);
    }
}