#pragma once

#include "core/IState.h"

class ShootState : public IState
{
public:

    void onEnter(Game&) override;

    void onExit(Game&) override;

    void handleEvent(
        Game&,
        const SDL_Event&) override;

    void update(
        Game&,
        float) override;

    void render(
        Game&) override;

private:

    float m_timer = 0.0f;
};