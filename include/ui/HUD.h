#pragma once

#include "ui/TextRenderer.h"

class Game;

class HUD
{
public:

    bool init();

    void shutdown();

    void render(
        Game& game);

private:

    TextRenderer m_text;
};