#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <string>

class TextRenderer
{
public:

    bool init();

    void shutdown();

    void drawText(
        SDL_Renderer* renderer,
        const std::string& text,
        int x,
        int y);

private:

    TTF_Font* m_font =
        nullptr;
};