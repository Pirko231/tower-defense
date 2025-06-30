#pragma once
#include <SFML/Graphics.hpp>
#include "../screenstatemachineinterface.hpp"

class ScreenState : public sf::Drawable
{
protected:
    IScreenStateMachine* stateMachine{};
public:
    ScreenState(IScreenStateMachine* _stateMachine) : stateMachine(_stateMachine) {}
    virtual void update() = 0;
};
