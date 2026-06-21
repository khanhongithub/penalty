#pragma once
#include <SDL2/SDL.h>

class Game;

class IState
{
public:
    virtual ~IState() = default;
    virtual void onEnter(Game& game) = 0;
    virtual void onExit(Game& game) = 0;
    virtual void handleEvent(
        Game& game,
        const SDL_Event& event) = 0;
    virtual void update(
        Game& game,
        float deltaTime) = 0;
    virtual void render(
        Game& game) = 0;
};

