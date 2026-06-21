#include "states/ResultState.h"

#include <iostream>
#include <memory>

#include "core/Game.h"
#include "states/AimState.h"
#include "states/GameOverState.h"

namespace
{
    float g_timer = 0.0f;
}

void ResultState::onEnter(Game& game)
{
    g_timer = 0.0f;

    auto& data =
        game.getData();

    if(data.lastShotGoal)
    {
        std::cout
            << "GOAL!"
            << std::endl;
    }
    else
    {
        std::cout
            << "SAVED!"
            << std::endl;
    }
}

void ResultState::onExit(Game&)
{
}

void ResultState::handleEvent(
    Game&,
    const SDL_Event&)
{
}

void ResultState::update(
    Game& game,
    float dt)
{
    g_timer += dt;

    if(g_timer < 2.0f)
    {
        return;
    }

    auto& data =
        game.getData();

    data.round++;

    if(data.round > data.maxRounds)
    {
        game.getStateMachine()
            .changeState(
                game,
                std::make_unique<GameOverState>());
    }
    else
    {
        game.getStateMachine()
            .changeState(
                game,
                std::make_unique<AimState>());
    }
}

void ResultState::render(Game& game)
{
    SDL_Renderer* renderer = game.getRenderer();
    auto& tr = game.getTextRenderer();
    auto& data = game.getData();

    // background color
    if (data.lastShotGoal)
    {
        SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255); // green
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255); // red
    }

    SDL_RenderClear(renderer);

    // TEXT IMPORTANT PART
    if (data.lastShotGoal)
    {
        tr.drawText(renderer, "GOAL!", 450, 250);
    }
    else
    {
        tr.drawText(renderer, "MISS!", 450, 250);
    }

    tr.drawText(
        renderer,
        "Press ENTER",
        400,
        320);
}