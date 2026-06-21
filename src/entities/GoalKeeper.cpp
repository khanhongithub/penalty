#include "entities/GoalKeeper.h"

#include <cstdlib>

void GoalKeeper::chooseDirection()
{
    int r = rand() % 3;

    switch(r)
    {
        case 0:
            m_direction =
                ShootZone::LEFT;
            break;

        case 1:
            m_direction =
                ShootZone::CENTER;
            break;

        default:
            m_direction =
                ShootZone::RIGHT;
            break;
    }
}

ShootZone
GoalKeeper::getDirection() const
{
    return m_direction;
}

void GoalKeeper::render(
    SDL_Renderer* renderer)
{
    int x = 620;

    switch(m_direction)
    {
        case ShootZone::LEFT:
            x = 450;
            break;

        case ShootZone::CENTER:
            x = 620;
            break;

        case ShootZone::RIGHT:
            x = 790;
            break;
    }

    SDL_Rect rect
    {
        x,
        100,
        60,
        120
    };

    SDL_SetRenderDrawColor(
        renderer,
        255,
        0,
        0,
        255);

    SDL_RenderFillRect(
        renderer,
        &rect);
}