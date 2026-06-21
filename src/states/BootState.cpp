#include "states/BootState.h"

#include <memory>

#include "core/Game.h"
#include "states/AimState.h"

void BootState::onEnter(Game&)
{
}

void BootState::onExit(Game&)
{
}

void BootState::handleEvent(
    Game& game,
    const SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN)
    {
        game.getStateMachine().changeState(
            game,
            std::make_unique<AimState>());
    }
}

void BootState::update(
    Game&,
    float)
{
}

void BootState::render(Game& game)
{
    SDL_Renderer* renderer = game.getRenderer();
    auto& tr = game.getTextRenderer();

    // background
    SDL_SetRenderDrawColor(renderer, 10, 20, 80, 255);
    SDL_RenderClear(renderer);

    // title
    tr.drawText(renderer, "PENALTY SHOOTOUT", 300, 150);

    // instruction
    tr.drawText(renderer, "PRESS ENTER TO START", 280, 300);
}