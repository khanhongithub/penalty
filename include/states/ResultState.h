#pragma once

#include "core/IState.h"

class ResultState : public IState
{
public:
    void onEnter(Game& game) override;

    void onExit(Game& game) override;

    void handleEvent(
        Game& game,
        const SDL_Event& event) override;

    void update(
        Game& game,
        float dt) override;

    void render(
        Game& game) override;
};