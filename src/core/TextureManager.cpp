#include "core/TextureManager.h"

#include <SDL2/SDL_image.h>

#include <iostream>

SDL_Texture*
TextureManager::loadTexture(
    const std::string& file,
    SDL_Renderer* renderer)
{
    SDL_Surface* surface =
        IMG_Load(file.c_str());

    if(!surface)
    {
        std::cout
            << "IMG_Load failed: "
            << file
            << " "
            << IMG_GetError()
            << std::endl;

        return nullptr;
    }

    SDL_Texture* texture =
        SDL_CreateTextureFromSurface(
            renderer,
            surface);

    SDL_FreeSurface(
        surface);

    if(!texture)
    {
        std::cout
            << "CreateTexture failed: "
            << SDL_GetError()
            << std::endl;
    }

    return texture;
}