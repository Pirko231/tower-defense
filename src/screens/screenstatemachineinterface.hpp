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

    virtual void setCurrentMap(const std::filesystem::path& _mapPath, int decorAmount, int health, int money) = 0;

    virtual void setCurrentEnemies(const std::filesystem::path& _enemyPath) = 0;

    Pressed& getPressed() { return pressed; }

    sf::RenderWindow* getWindow() { return window; }

    virtual ScreenState* getMainMenuScreen() = 0;

    virtual ScreenState* getGameScreen() = 0;

    virtual ScreenState* getMapSelectionScreen() = 0;

    virtual void setState(ScreenState*) = 0;
};
