#pragma once

#include <SDL2/SDL.h>

#include "math/Vector2.h"

class Ball
{
public:

    Ball();

    void reset();

    void update(float dt);

    void render(
        SDL_Renderer* renderer);

    void shoot(
        const Vector2& velocity);

    bool isMoving() const;

    const Vector2& getPosition() const;

    void loadTexture(SDL_Renderer* renderer);

    void destroyTexture();
    
private:

    Vector2 m_position;

    Vector2 m_velocity;

    int m_size;

    SDL_Texture* m_texture = nullptr;
};