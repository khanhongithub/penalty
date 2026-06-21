#pragma once 
#include <SDL2/SDL.h>

#include "core/StateMachine.h"
#include "core/GameData.h"
#include "ui/HUD.h"
#include "ui/TextRenderer.h"

class Game
{
public:
    Game();
    ~Game();
    bool init();
    void run();
    void shutdown();
    SDL_Renderer* getRenderer();
    SDL_Window* getWindow();
    StateMachine& getStateMachine();
    GameData& getData();
    HUD& getHUD();
    TextRenderer& getTextRenderer();
private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    bool m_running;
    StateMachine m_stateMachine;
    GameData m_data;
    HUD m_hud;
    TextRenderer m_textRenderer;
};