#pragma once

#include <SDL2/SDL.h>
#include "core/ShootZone.h"

class GoalKeeper
{
public:
    GoalKeeper();

    void reset();
    void update(float dt);

    void render(SDL_Renderer* renderer);

    ShootZone getDirection() const;

    void loadTexture(SDL_Renderer* renderer);

    void destroyTexture();


private:
    SDL_Texture* m_texture = nullptr;

    ShootZone m_direction;

    float m_timer = 0.0f;
};