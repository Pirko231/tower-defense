#include "gamescreen.hpp"

GameScreen::GameScreen(IScreenStateMachine* _stateMachine)
    : ScreenState(_stateMachine), map(),
    enemyManager(&map, &health, &money), waveManager(&map, &enemyManager),
    bulletManager(&enemyManager),
    towerManager(&map, &enemyManager, &bulletManager), towerManagerProxy(&towerManager), buildingUI(&map, &towerManagerProxy, &money, &health),
    waveCounter(util::AssetLoader::get().font)
{
    waveButton.setScale({0.2f,0.2f});
    waveButton.setPosition({util::mapSize.x * util::tileSize.x / 2.f - waveButton.getGlobalBounds().size.x / 2.f, 0.f});

    waveCounter.setString("test");
    waveCounter.setPosition({waveButton.getPosition().x + waveButton.getGlobalBounds().size.x + 20.f, waveButton.getGlobalBounds().getCenter().y - waveCounter.getGlobalBounds().size.y / 2.f - 20.f});

    pauseMenu.setScale({0.8f,0.8f});
    pauseMenu.setPosition({util::mapSize.x * util::tileSize.x / 2.f - pauseMenu.getGlobalBounds().size.x / 2.f, util::mapSize.y * util::tileSize.y / 2.f - pauseMenu.getGlobalBounds().size.y / 2.f});
}

void GameScreen::update()
{
    managePauseMenu();
    if(paused)
        return; // wyjdz kiedy zapauzowane

    waveButton.update();

    towerManager.update();

    bulletManager.update();

    enemyManager.update();

    waveManager.update();
    // ustawienie licznika fal
    {
        sf::String waveString{std::to_string(waveManager.getWaves())};
        waveString += '/';
        waveString += std::to_string(waveManager.getMaxWaves());
        waveCounter.setString(waveString);
    }

    // klikanie myszki
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

    if (stateMachine->getPressed()[sf::Mouse::Button::Right].released)
        buildingUI.leaveBuildMode();

    // skroty klawiaturowe
    if(stateMachine->getPressed()[sf::Keyboard::Key::Space].released)
        if(!waveManager.isWaveActive())
            waveManager.nextWave();
        
    if(stateMachine->getPressed()[sf::Keyboard::Key::Escape].released)
        buildingUI.leaveBuildMode();

    if(stateMachine->getPressed()[sf::Keyboard::Key::Backspace].released)
    {
        money += towerManager.destructTowers(buildingUI.getMapPointerPosition()) / 2;
        buildingUI.leaveBuildMode();
    }
}

void GameScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(map,states);

    target.draw(waveButton,states);
    target.draw(waveCounter,states);

    target.draw(towerManager,states);

    target.draw(enemyManager,states);

    target.draw(bulletManager,states);

    target.draw(buildingUI,states);

    if(paused)
        target.draw(pauseMenu,states);
}

void GameScreen::managePauseMenu()
{
    // ustawienie zapalzowania
    if(stateMachine->getPressed()[sf::Keyboard::Key::Escape].released)
        paused = !paused;
    
    if (stateMachine->getPressed()[sf::Mouse::Button::Left].released)
    {
        if(pauseMenu.getQuit(sf::Mouse::getPosition(*stateMachine->getWindow())))
        {
            resetLevel();
            stateMachine->setState(stateMachine->getMapSelectionScreen());
        }
    }

}

void GameScreen::resetLevel()
{
    paused = false;
    buildingUI.leaveBuildMode();

}
