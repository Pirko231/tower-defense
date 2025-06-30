#pragma once
#include "states/mainmenuscreen.hpp"
#include "states/gamescreen.hpp"
#include "screenstatemachineinterface.hpp"

class ScreenStateMachine : public sf::Drawable, public IScreenStateMachine
{
    std::unique_ptr<ScreenState> mainMenuScreen;
    std::unique_ptr<ScreenState> gameScreen;
    ScreenState* currentState{};
public:
    ScreenStateMachine(Pressed& pressed, sf::RenderWindow* _window);

    void update();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setState(ScreenState* newState) override {currentState = newState;}
    ScreenState* getMainMenuScreen() override {return mainMenuScreen.get();}
    ScreenState* getGameScreen() override {return gameScreen.get();}
};
