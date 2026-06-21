#pragma once

#include <SDL2/SDL.h>
#include <memory>

class Game;
class IState;

class StateMachine
{
public:
    void changeState(
        Game& game,
        std::unique_ptr<IState> newState);

    void handleEvent(
        Game& game,
        const SDL_Event& event);

    void update(
        Game& game,
        float dt);

    void render(
        Game& game);

private:
    std::unique_ptr<IState> m_currentState;
};