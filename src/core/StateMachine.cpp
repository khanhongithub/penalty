#include "core/StateMachine.h"
#include "core/IState.h"

void StateMachine::changeState(
    Game& game,
    std::unique_ptr<IState> newState)
{
    if (m_currentState)
    {
        m_currentState->onExit(game);
    }

    m_currentState = std::move(newState);

    if (m_currentState)
    {
        m_currentState->onEnter(game);
    }
}

void StateMachine::handleEvent(
    Game& game,
    const SDL_Event& event)
{
    if (m_currentState)
    {
        m_currentState->handleEvent(game, event);
    }
}

void StateMachine::update(
    Game& game,
    float dt)
{
    if (m_currentState)
    {
        m_currentState->update(game, dt);
    }
}

void StateMachine::render(
    Game& game)
{
    if (m_currentState)
    {
        m_currentState->render(game);
    }
}