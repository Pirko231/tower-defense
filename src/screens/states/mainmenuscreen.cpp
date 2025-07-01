#include "mainmenuscreen.hpp"

MainMenuScreen::MainMenuScreen(IScreenStateMachine* _screenMachine)
    : ScreenState(_screenMachine), playButton(util::AssetLoader::get().font)
{
    playButton.setString("Play");
}

void MainMenuScreen::update()
{
    playButton.update();

    if (stateMachine->getPressed()[sf::Mouse::Button::Left].released)
        if (playButton.isPressed(sf::Mouse::getPosition(*stateMachine->getWindow())))
            stateMachine->setState(stateMachine->getMapSelectionScreen());
}

void MainMenuScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(playButton);
}
