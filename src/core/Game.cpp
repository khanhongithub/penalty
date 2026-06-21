#include <iostream>

#include <SDL2/SDL_image.h>

#include "core/Game.h"
#include "core/TextureManager.h"
#include "states/BootState.h"

Game::Game()
    : m_window(nullptr),
      m_renderer(nullptr),
      m_running(false)
{
}

Game::~Game()
{
    shutdown();
}

bool Game::init()
{
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL init failed\n";
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
    std::cout
        << "IMG_Init failed: "
        << IMG_GetError()
        << std::endl;

    return false;
    }

    m_window = SDL_CreateWindow(
        "Penalty Shootout 2",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280,
        720,
        SDL_WINDOW_SHOWN);

    if (!m_window)
    {
        return false;
    }

    m_renderer = SDL_CreateRenderer(
        m_window,
        -1,
        SDL_RENDERER_ACCELERATED);

    if (!m_renderer)
    {
        return false;
    }

    m_stateMachine.changeState(
        *this,
        std::make_unique<BootState>());

    m_hud.init();
    m_textRenderer.init();

    m_data.ball.loadTexture(
    m_renderer);
    return true;
}

void Game::run()
{
    m_running = true;

    Uint64 last = SDL_GetPerformanceCounter();

    while (m_running)
    {
        Uint64 now = SDL_GetPerformanceCounter();

        float dt =
            (now - last) /
            static_cast<float>(
                SDL_GetPerformanceFrequency());

        last = now;

        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                m_running = false;
            }

            m_stateMachine.handleEvent(
                *this,
                event);
        }



        m_stateMachine.update(
            *this,
            dt);

        SDL_SetRenderDrawColor(
            m_renderer,
            20,
            120,
            20,
            255);

        SDL_RenderClear(
            m_renderer);

        m_stateMachine.render(
            *this);

        m_hud.render(
            *this);

        SDL_RenderPresent(
            m_renderer);
    }
}

void Game::shutdown()
{
    if (m_renderer)
    {
        SDL_DestroyRenderer(
            m_renderer);
    }

    if (m_window)
    {
        SDL_DestroyWindow(
            m_window);
    }

    SDL_Quit();

    IMG_Quit();

    m_data.ball.destroyTexture();
}

SDL_Renderer* Game::getRenderer()
{
    return m_renderer;
}

SDL_Window* Game::getWindow()
{
    return m_window;
}

StateMachine& Game::getStateMachine()
{
    return m_stateMachine;
}

GameData& Game::getData()
{
    return m_data;
}

HUD& Game::getHUD()
{
    return m_hud;
}

TextRenderer& Game::getTextRenderer()
{
    return m_textRenderer;
}