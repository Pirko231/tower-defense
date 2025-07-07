#include "mainmenuscreen.hpp"

MainMenuScreen::MainMenuScreen(IScreenStateMachine* _screenMachine)
    : ScreenState(_screenMachine)
{
    playButton.setPosition({util::mapSize.x * util::tileSize.x / 2.f - playButton.getGlobalBounds().size.x / 2.f, util::mapSize.y * util::tileSize.y / 2.f - playButton.getGlobalBounds().size.y / 2.f});
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
