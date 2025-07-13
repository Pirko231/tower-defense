#include "gamescreen.hpp"

GameScreen::GameScreen(IScreenStateMachine* _stateMachine)
    : ScreenState(_stateMachine), map(),
    towerManager(&map), towerManagerProxy(&towerManager), buildingUI(&map, &towerManagerProxy, &money, &health),
    enemyManager(&map, &health), waveManager(&map, &enemyManager)
{
    //towerManagerProxy.addTower({19,11}, TowerType::Archer);
    //towerManagerProxy.addTower({12,11}, TowerType::Archer);
}

void GameScreen::update()
{
    towerManager.update();

    enemyManager.update();

    waveManager.update();

    if (stateMachine->getPressed()[sf::Mouse::Button::Left].released)
        buildingUI.click(sf::Mouse::getPosition(*stateMachine->getWindow()));
}

void GameScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(map,states);

    target.draw(towerManager,states);

    target.draw(enemyManager,states);

    target.draw(buildingUI,states);
}
