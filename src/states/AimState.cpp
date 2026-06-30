#include <iostream>
#include "states/AimState.h"

#include <memory>

#include "core/Game.h"
#include "states/ShootState.h"

void AimState::onEnter(Game&)
{
}

void AimState::onExit(Game&)
{
}

void AimState::handleEvent(
    Game& game,
    const SDL_Event& event)
{
    if (event.type != SDL_KEYDOWN)
    {
        return;
    }

    if(event.type == SDL_KEYDOWN)
    {
        std::cout
            << event.key.keysym.sym
            << std::endl;
    }
    
    auto& data = game.getData();

    switch(event.key.keysym.sym)
    {
        case SDLK_LEFT:
            std::cout << "Left pressed" << std::endl;
            data.selectedZone =
                ShootZone::LEFT;
            break;

        case SDLK_UP:
            std::cout << "Up pressed" << std::endl;        
            data.selectedZone =
                ShootZone::CENTER;
            break;

        case SDLK_RIGHT:
            std::cout << "Right pressed" << std::endl;
            data.selectedZone =
                ShootZone::RIGHT;
            break;

        case SDLK_RETURN:
            std::cout << "SPACE pressed" << std::endl;
            game.getStateMachine()
                .changeState(
                    game,
                    std::make_unique<ShootState>());

            break;
    }
}

void AimState::update(
    Game&,
    float)
{
}

void AimState::render(Game& game)
{
    SDL_Renderer* renderer = game.getRenderer();

    SDL_Rect left   = {400, 500, 100, 80};
    SDL_Rect center = {600, 500, 100, 80};
    SDL_Rect right  = {800, 500, 100, 80};

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &left);
    SDL_RenderDrawRect(renderer, &center);
    SDL_RenderDrawRect(renderer, &right);

    SDL_Rect* selected = nullptr;

    switch (game.getData().selectedZone)
    {
        case ShootZone::LEFT: selected = &left; break;
        case ShootZone::CENTER: selected = &center; break;
        case ShootZone::RIGHT: selected = &right; break;
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(renderer, selected);

    SDL_RenderClear(renderer);

    game.getHUD().render(game);

    game.getTextRenderer().drawText(
        renderer,
        "SELECT DIRECTION",
        450,
        100
    );
    
}