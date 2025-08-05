#include "mapselectionscreen.hpp"

#include "assetloader.hpp"

MapSelectionScreen::MapSelectionScreen(IScreenStateMachine* _stateMachine)
    : ScreenState(_stateMachine), background(util::AssetLoader::get().background), title(util::AssetLoader::get().font),
    buttonInfo("resources/data/maps.xml"), mapButtons({btn::MapButton{"meadows", "map1.txt", "enemies1.txt", 2},
    btn::MapButton{"swamp", "map2.txt", "enemies2.txt", 0},
    btn::MapButton{"desert", "map3.txt", "enemies3.txt", 7},
    btn::MapButton{"ice lake", "map4.txt", "enemies4.txt", 8},
    btn::MapButton{"krzeszowice", "map5.txt", "enemies5.txt", 7},
    btn::MapButton{"Alwernia", "map6.txt", "enemies6.txt", 10}})
{
    mapButtons[0].setPosition({80.f,150.f}); // 180,150
    for (int i = 1; i < 3; i++)
        mapButtons[i].setPosition({mapButtons[i - 1].getPosition().x + mapButtons[i].getGlobalBounds().size.x * 1.3f, mapButtons[i - 1].getPosition().y});

    mapButtons[3].setPosition({80.f,460.f}); // 180,500
    for (int i = 4; i < 6; i++)
        mapButtons[i].setPosition({mapButtons[i - 1].getPosition().x + mapButtons[i].getGlobalBounds().size.x * 1.3f, mapButtons[i - 1].getPosition().y});

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
                stateMachine->setCurrentMap(button.getMap(), button.getDecorationAmount());
                stateMachine->setCurrentEnemies(button.getEnemies());
                stateMachine->setState(stateMachine->getGameScreen());
            }
}

void MapSelectionScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(background,states);
    target.draw(title,states);
    for (auto& button : mapButtons)
        target.draw(button,states);
}
