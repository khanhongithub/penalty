#include <iostream>

#include "entities/Ball.h"
#include "core/TextureManager.h"


Ball::Ball()
{
    m_size = 40;

    reset();
}

void Ball::reset()
{
    m_position =
    {
        620.0f,
        520.0f
    };

    m_velocity =
    {
        0.0f,
        0.0f
    };
}

void Ball::shoot(
    const Vector2& velocity)
{
    m_velocity = velocity;
}

void Ball::update(
    float dt)
{
    m_position =
        m_position +
        m_velocity * dt;
}

bool Ball::isMoving() const
{
    return
        m_velocity.x != 0.0f ||
        m_velocity.y != 0.0f;
}

const Vector2&
Ball::getPosition() const
{
    return m_position;
}


void Ball::loadTexture(SDL_Renderer* renderer)
{
    m_texture =
        TextureManager::loadTexture(
            "assets/sprites/ball.png",
            renderer);

    std::cout
        << "Loaded texture = "
        << m_texture
        << std::endl;

    std::cout << "Ball addr = " << this << std::endl;
}


void Ball::destroyTexture()
{
    if(m_texture)
    {
        SDL_DestroyTexture(
            m_texture);

        m_texture = nullptr;
    }
}

void Ball::render(
    SDL_Renderer* renderer)
{

    std::cout
        << "Render texture = "
        << m_texture
        << std::endl;
    if(!m_texture)
    {
        return;
    }

    SDL_Rect dst
    {
        static_cast<int>(m_position.x),
        static_cast<int>(m_position.y),
        m_size,
        m_size
    };

    SDL_RenderCopy(
        renderer,
        m_texture,
        nullptr,
        &dst);
    
    std::cout << "Ball addr = " << this << std::endl;
}

#include "entities/Ball.h"

ShootZone Ball::getZone() const
{
    float x = m_position.x;

    if (x < 500)
        return ShootZone::LEFT;

    if (x < 700)
        return ShootZone::CENTER;

    return ShootZone::RIGHT;
}
