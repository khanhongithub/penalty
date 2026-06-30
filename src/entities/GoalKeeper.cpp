#include "entities/GoalKeeper.h"
#include <cstdlib>

GoalKeeper::GoalKeeper()
{
    reset();
}

void GoalKeeper::reset()
{
    m_timer = 0.0f;

    int r = rand() % 3;

    m_direction = static_cast<ShootZone>(r);
}

void GoalKeeper::update(float dt)
{
    m_timer += dt;

}

ShootZone GoalKeeper::getDirection() const
{
    return m_direction;
}

void GoalKeeper::render(SDL_Renderer* renderer)
{
    SDL_Rect rect;

    switch (m_direction)
    {
        case ShootZone::LEFT:
            rect = {400, 300, 80, 120};
            break;

        case ShootZone::CENTER:
            rect = {600, 300, 80, 120};
            break;

        case ShootZone::RIGHT:
            rect = {800, 300, 80, 120};
            break;
    }

    SDL_SetRenderDrawColor(renderer, 255, 200, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}