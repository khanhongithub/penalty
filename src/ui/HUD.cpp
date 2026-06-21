#include <string>
#include <iostream>

#include "ui/HUD.h"

#include "core/Game.h"


bool HUD::init()
{
    return m_text.init();
}

void HUD::shutdown()
{
    m_text.shutdown();
}


void HUD::render(
    Game& game)
{
    std::cout << "HUD render\n";
    auto& data =
        game.getData();

    SDL_Renderer* renderer =
        game.getRenderer();

    m_text.drawText(
        renderer,
        "Score: " +
        std::to_string(
            data.score),
        20,
        20);

    m_text.drawText(
        renderer,
        "Round: " +
        std::to_string(
            data.round),
        20,
        60);
}
