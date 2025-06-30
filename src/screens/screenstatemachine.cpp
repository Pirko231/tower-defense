//
// Created by szymek on 30.06.25.
//

#include "screenstatemachine.hpp"

ScreenStateMachine::ScreenStateMachine(Pressed& _pressed, sf::RenderWindow* _window)
    :
    mainMenuScreen(std::make_unique<MainMenuScreen>(this,_pressed, _window)), gameScreen(std::make_unique<GameScreen>(this,_pressed, _window))
{
    currentState = getMainMenuScreen();

    //currentState = getGameScreen();
}

void ScreenStateMachine::update()
{
    currentState->update();
}

void ScreenStateMachine::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(*currentState, states);
}
