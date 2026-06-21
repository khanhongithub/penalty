#pragma once

#include <SDL2/SDL.h>

#include "core/ShootZone.h"

class GoalKeeper
{
public:

    void chooseDirection();

    ShootZone getDirection() const;

    void render(
        SDL_Renderer* renderer);

private:

    ShootZone m_direction =
        ShootZone::CENTER;
};