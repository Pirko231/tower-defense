#include "mainmenuscreen.hpp"

MainMenuScreen::MainMenuScreen(IScreenStateMachine* _screenMachine, Pressed& _pressed, sf::RenderWindow* _window)
    : ScreenState(_screenMachine), pressed(_pressed), window(_window), playButton(util::AssetLoader::get().font)
{
    playButton.setString("Play");
}

void MainMenuScreen::update()
{
    playButton.update();

    if (pressed[sf::Mouse::Button::Left].released)
        if (playButton.isPressed(sf::Mouse::getPosition(*window)))
            stateMachine->setState(stateMachine->getGameScreen());
}

void MainMenuScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(playButton);
}
