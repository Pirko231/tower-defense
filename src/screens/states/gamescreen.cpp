#include "gamescreen.hpp"

GameScreen::GameScreen(IScreenStateMachine* _stateMachine)
    : ScreenState(_stateMachine), map(),
    towerManager(&map), towerManagerProxy(&towerManager), buildingUI(&map, &towerManagerProxy, &money, &health),
    enemyManager(&map, &health), waveManager(&map, &enemyManager)
{
    waveButton.setScale({0.2f,0.2f}); // zepsulo sie cos ze skala - manualnei pomnozylem * 0.2
    waveButton.setPosition({util::mapSize.x * util::tileSize.x / 2.f - waveButton.getGlobalBounds().size.x * 0.2f / 2.f, 0.f});
}

void GameScreen::update()
{
    waveButton.update();

    towerManager.update();

    enemyManager.update();

    waveManager.update();

    if (stateMachine->getPressed()[sf::Mouse::Button::Left].released)
    {
        if (waveButton.isPressed(sf::Mouse::getPosition(*stateMachine->getWindow())))
        {
            if(!waveManager.isWaveActive())
            {
                waveManager.nextWave();
            }
        }
        else
            buildingUI.click(sf::Mouse::getPosition(*stateMachine->getWindow()));
    }
}

void GameScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(map,states);

    target.draw(waveButton,states);

    target.draw(towerManager,states);

    target.draw(enemyManager,states);

    target.draw(buildingUI,states);
}
