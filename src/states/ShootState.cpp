#include <iostream>
#include "states/ShootState.h"

#include <memory>

#include "core/Game.h"
#include "states/ResultState.h"

void ShootState::onEnter(Game& game)
{
    auto& data = game.getData();

    data.keeper.reset();   // 👈 IMPORTANT
    data.ball.reset();

    Vector2 velocity;

    switch(data.selectedZone)
    {
        case ShootZone::LEFT:
            velocity = {-220, -250};
            break;

        case ShootZone::CENTER:
            velocity = {0, -300};
            break;

        case ShootZone::RIGHT:
            velocity = {220, -250};
            break;
    }

    data.ball.shoot(velocity);
}

void ShootState::onExit(Game&)
{
}

void ShootState::handleEvent(
    Game&,
    const SDL_Event&)
{
}

void ShootState::update(Game& game, float dt)
{
    auto& data = game.getData();

    data.ball.update(dt);
    data.keeper.update(dt);

    m_timer += dt;

    // delay nhỏ để ball bay trước
    if (m_timer < 0.5f)
        return;

    if (data.ball.getPosition().y < 100)
    {
        ShootZone ballZone = data.ball.getZone();

        if (ballZone == data.keeper.getDirection())
        {
            data.lastShotGoal = false;
        }
        else
        {
            data.lastShotGoal = true;
            data.score++;
        }

        game.getStateMachine().changeState(
            game,
            std::make_unique<ResultState>());
    }
}

void ShootState::render(
    Game& game)
{
    SDL_Renderer* renderer =
        game.getRenderer();

    SDL_SetRenderDrawColor(
        renderer,
        0,
        120,
        0,
        255);


    auto& data =
        game.getData();

    data.ball.render(
        renderer);

    data.keeper.render(
        renderer);
}