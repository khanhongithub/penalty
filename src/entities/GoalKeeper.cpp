#include <iostream>

#include "entities/GoalKeeper.h"
#include "core/TextureManager.h"
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
    if (!m_texture)
    {
        return;
    }

    int x = 560;

    switch (m_direction)
    {
        case ShootZone::LEFT:
            x = 360;
            break;

        case ShootZone::CENTER:
            x = 560;
            break;

        case ShootZone::RIGHT:
            x = 760;
            break;
    }

    SDL_Rect dst
    {
        x,
        80,
        180,
        180
    };

    SDL_RenderCopy(
        renderer,
        m_texture,
        nullptr,
        &dst);
}

void GoalKeeper::loadTexture(
    SDL_Renderer* renderer)
{
    m_texture =
        TextureManager::loadTexture(
            "assets/sprites/keeper.png",
            renderer);

    std::cout
        << "Keeper texture = "
        << m_texture
        << std::endl;
}

void GoalKeeper::destroyTexture()
{
    if (m_texture)
    {
        SDL_DestroyTexture(
            m_texture);

        m_texture = nullptr;
    }
}