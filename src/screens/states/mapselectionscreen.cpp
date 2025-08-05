#include "mapselectionscreen.hpp"

#include "assetloader.hpp"

MapSelectionScreen::MapSelectionScreen(IScreenStateMachine* _stateMachine)
    : ScreenState(_stateMachine), background(util::AssetLoader::get().background), title(util::AssetLoader::get().font),
    buttonInfo("resources/data/maps.xml"), mapButtons({btn::MapButton{buttonInfo[0]},
    btn::MapButton{buttonInfo[1]},
    btn::MapButton{buttonInfo[2]},
    btn::MapButton{buttonInfo[3]},
    btn::MapButton{buttonInfo[4]},
    btn::MapButton{buttonInfo[5]}})
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
