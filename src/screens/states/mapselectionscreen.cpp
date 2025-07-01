#include "mapselectionscreen.hpp"

#include "assetloader.hpp"

MapSelectionScreen::MapSelectionScreen(IScreenStateMachine* _stateMachine)
    : ScreenState(_stateMachine), title(util::AssetLoader::get().font),
    mapButtons({btn::MapButton{util::AssetLoader::get().font, "resources/maps/map1.txt"},
    btn::MapButton{util::AssetLoader::get().font, "resources/maps/map2.txt"},
    btn::MapButton{util::AssetLoader::get().font, "resources/maps/map3.txt"},
    btn::MapButton{util::AssetLoader::get().font, "resources/maps/map4.txt"},
    btn::MapButton{util::AssetLoader::get().font, "resources/maps/map5.txt"},
    btn::MapButton{util::AssetLoader::get().font, "resources/maps/map6.txt"}})
{
    mapButtons[0].setPosition({180.f,150.f});
    for (int i = 1; i < 3; i++)
        mapButtons[i].setPosition({mapButtons[i - 1].getPosition().x + mapButtons[i].getGlobalBounds().size.x * 1.5f, mapButtons[i - 1].getPosition().y});

    mapButtons[3].setPosition({180.f,500.f});
    for (int i = 4; i < 6; i++)
        mapButtons[i].setPosition({mapButtons[i - 1].getPosition().x + mapButtons[i].getGlobalBounds().size.x * 1.5f, mapButtons[i - 1].getPosition().y});

    title.setString("Map Selection");
    title.setCharacterSize(80);
    title.setPosition({355.f, 20.f});
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
    target.draw(title,states);
    for (auto& button : mapButtons)
        target.draw(button,states);
}
