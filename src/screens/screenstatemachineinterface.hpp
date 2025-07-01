#pragma once
#include "pressed.hpp"
#include "states/screenstate.hpp"

class ScreenState;

class IScreenStateMachine
{
protected:
    Pressed& pressed;
    sf::RenderWindow* window{};

public:
    IScreenStateMachine(Pressed& _pressed, sf::RenderWindow* _window)
        : pressed{_pressed}, window{_window}
    {}

    Pressed& getPressed() { return pressed; }

    sf::RenderWindow* getWindow() { return window; }

    virtual ScreenState* getMainMenuScreen() = 0;

    virtual ScreenState* getGameScreen() = 0;

    virtual ScreenState* getMapSelectionScreen() = 0;

    virtual void setState(ScreenState*) = 0;
};
