#include "ui/TextRenderer.h"

#include <iostream>

bool TextRenderer::init()
{
    if(TTF_Init() != 0)
    {
        return false;
    }

    m_font = TTF_OpenFont(
        "assets/fonts/DejaVuSans.ttf",
        28);

    std::cout
        << "font="
        << m_font
        << std::endl;

    return m_font != nullptr;
}

void TextRenderer::shutdown()
{
    if(m_font)
    {
        TTF_CloseFont(
            m_font);
    }

    TTF_Quit();
}

void TextRenderer::drawText(
    SDL_Renderer* renderer,
    const std::string& text,
    int x,
    int y)
{

    if(!m_font)
    {
        std::cout
            << "Font not loaded!"
            << std::endl;
        return;
    }

    SDL_Color color =
    {
        255,
        255,
        255,
        255
    };

    SDL_Surface* surface =
        TTF_RenderText_Solid(
            m_font,
            text.c_str(),
            color);

    if(!surface)
    {
        std::cout
            << TTF_GetError()
            << std::endl;
        return;
    }

    SDL_Texture* texture =
        SDL_CreateTextureFromSurface(
            renderer,
            surface);

    SDL_Rect dst
    {
        x,
        y,
        surface->w,
        surface->h
    };

    SDL_RenderCopy(
        renderer,
        texture,
        nullptr,
        &dst);

    SDL_FreeSurface(
        surface);

    SDL_DestroyTexture(
        texture);
}