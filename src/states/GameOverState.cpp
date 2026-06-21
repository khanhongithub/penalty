#include "states/GameOverState.h"

#include <memory>
#include <iostream>

#include "core/Game.h"
#include "states/AimState.h"

void GameOverState::onEnter(Game& game)
{
    std::cout
    << "Final Score = "
    << game.getData().score
    << std::endl;
}

void GameOverState::onExit(Game&)
{
}

void GameOverState::handleEvent(
    Game& game,
    const SDL_Event& event)
{
    if (event.type != SDL_KEYDOWN)
    {
        return;
    }

    if (event.key.keysym.sym == SDLK_r)
    {
        auto& data = game.getData();

        data.score = 0;
        data.round = 1;
        data.lastShotGoal = false;

        game.getStateMachine().changeState(
            game,
            std::make_unique<AimState>());
    }
}

void GameOverState::update(
    Game&,
    float)
{
}

void GameOverState::render(Game& game)
{
    SDL_Renderer* renderer = game.getRenderer();
    auto& tr = game.getTextRenderer();
    auto& data = game.getData();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    tr.drawText(renderer, "GAME OVER", 380, 200);

    tr.drawText(
        renderer,
        "Final Score: " + std::to_string(data.score),
        360,
        260);

    tr.drawText(
        renderer,
        "Press ENTER to restart",
        300,
        320);
}