#include "gamescreen.hpp"

GameScreen::GameScreen(Pressed& _pressed, sf::RenderWindow* _window)
    : pressed(_pressed), window(_window),
    towerManager(&map), towerManagerProxy(&towerManager), buildingUI(&map)
{
    towerManagerProxy.addTower({19,11}, TowerType::Archer);
    towerManagerProxy.addTower({12,11}, TowerType::Archer);
}

void GameScreen::update()
{
    towerManager.update();

    if (pressed[sf::Mouse::Button::Left].released)
        buildingUI.click(sf::Mouse::getPosition(*window));
}

void GameScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(map,states);

    target.draw(towerManager,states);

    target.draw(buildingUI,states);
}
