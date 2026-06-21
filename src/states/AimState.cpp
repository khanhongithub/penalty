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

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Rect box{400, 200, 300, 200};

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &box);

    auto& hud = game.getHUD();
    auto& tr = game.getTextRenderer();

    tr.drawText(renderer, "LEFT", 420, 250);
    tr.drawText(renderer, "CENTER", 420, 300);
    tr.drawText(renderer, "RIGHT", 420, 350);
}