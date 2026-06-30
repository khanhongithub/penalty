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

private:
    ShootZone m_direction;

    float m_timer = 0.0f;
};