#pragma once

#include "core/IState.h"

class AimState : public IState
{
public:

    void onEnter(Game&) override;

    void onExit(Game&) override;

    void handleEvent(
        Game& game,
        const SDL_Event& event) override;

    void update(
        Game& game,
        float dt) override;

    void render(
        Game& game) override;
};