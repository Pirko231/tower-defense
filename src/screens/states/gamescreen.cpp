#include "gamescreen.hpp"

GameScreen::GameScreen(IScreenStateMachine* _stateMachine)
    : ScreenState(_stateMachine), map(),
    enemyManager(&map, &health), waveManager(&map, &enemyManager),
    towerManager(&map, &enemyManager), towerManagerProxy(&towerManager), buildingUI(&map, &towerManagerProxy, &money, &health),
    waveCounter(util::AssetLoader::get().font)
{
    waveButton.setScale({0.2f,0.2f});
    waveButton.setPosition({util::mapSize.x * util::tileSize.x / 2.f - waveButton.getGlobalBounds().size.x / 2.f, 0.f});

    waveCounter.setString("test");
    waveCounter.setPosition({waveButton.getPosition().x + waveButton.getGlobalBounds().size.x + 20.f, waveButton.getGlobalBounds().getCenter().y - waveCounter.getGlobalBounds().size.y / 2.f - 20.f});
}

void GameScreen::update()
{
    waveButton.update();

    towerManager.update();

    enemyManager.update();

    waveManager.update();
    // ustawienie licznika fal
    {
        sf::String waveString{std::to_string(waveManager.getWaves() + 1)};
        waveString += '/';
        waveString += std::to_string(waveManager.getMaxWaves());
        waveCounter.setString(waveString);
    }

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
    target.draw(waveCounter,states);

    target.draw(towerManager,states);

    target.draw(enemyManager,states);

    target.draw(buildingUI,states);
}
