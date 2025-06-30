#pragma once
#include "mainmenuscreen.hpp"
#include "gamescreen.hpp"

class ScreenStateMachine : public sf::Drawable
{
    std::unique_ptr<ScreenState> mainMenuScreen;
    std::unique_ptr<ScreenState> gameScreen;
    ScreenState* currentState{};
public:
    ScreenStateMachine(Pressed& pressed, sf::RenderWindow* _window);

    void update();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setState(ScreenState* newState) {currentState = newState;}
    ScreenState* getMainMenuScreen() {return mainMenuScreen.get();}
    ScreenState* getGameScreen() {return gameScreen.get();}
};
