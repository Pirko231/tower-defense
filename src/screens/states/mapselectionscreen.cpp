#include "mapselectionscreen.hpp"

#include "assetloader.hpp"

MapSelectionScreen::MapSelectionScreen(IScreenStateMachine* _stateMachine)
    : ScreenState(_stateMachine),
    mapButtons({btn::MapButton{util::AssetLoader::get().font, "resources/maps/map1.txt"}})
{

}

void MapSelectionScreen::update()
{
    if (stateMachine->getPressed()[sf::Mouse::Button::Left].released)
        for (auto& button : mapButtons)
            if (button.isPressed(sf::Mouse::getPosition(*stateMachine->getWindow())))
            {
                stateMachine->setCurrentMap(button.getMap());
                stateMachine->setState(stateMachine->getGameScreen());
            }
}

void MapSelectionScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto& button : mapButtons)
        target.draw(button,states);
}
