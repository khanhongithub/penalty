#include <iostream>
#include "states/ShootState.h"

#include <memory>

#include "core/Game.h"
#include "states/ResultState.h"

void ShootState::onEnter(
    Game& game)
{
    std::cout << "ShootState entered\n";
    m_timer = 0.0f;

    auto& data =
        game.getData();

    data.ball.reset();

    Vector2 velocity;

    switch(data.selectedZone)
    {
        case ShootZone::LEFT:
            velocity =
            {
                -220.0f,
                -250.0f
            };
            break;

        case ShootZone::CENTER:
            velocity =
            {
                0.0f,
                -300.0f
            };
            break;

        case ShootZone::RIGHT:
            velocity =
            {
                220.0f,
                -250.0f
            };
            break;
    }

    data.ball.shoot(
        velocity);
}

void ShootState::onExit(Game&)
{
}

void ShootState::handleEvent(
    Game&,
    const SDL_Event&)
{
}

void ShootState::update(
    Game& game,
    float dt)
{
    auto& data =
        game.getData();

    data.ball.update(dt);

    m_timer += dt;

    if(m_timer > 1.5f)
    {
        data.lastShotGoal =
        (
            data.selectedZone
            !=
            data.keeper.getDirection()
        );

        if(data.lastShotGoal)
        {
            data.score++;
        }

        game.getStateMachine()
            .changeState(
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