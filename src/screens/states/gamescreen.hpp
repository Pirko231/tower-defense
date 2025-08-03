#pragma once
#include "pressed.hpp"
#include "screenstate.hpp"
#include "managers/towermanagerproxy.hpp"
#include "managers/enemymanager.hpp"
#include "managers/wavemanager.hpp"
#include "managers/bulletmanager.hpp"
#include "../map.hpp"
#include "../../game/buildingui.hpp"
#include "../../buttons/playbutton.hpp"
#include "../pauseMenu.hpp"

class GameScreen : public ScreenState
{
    int money{100};
    int health{100};
    Map map;
    EnemyManager enemyManager;
    WaveManager waveManager;
    BulletManager bulletManager;
    TowerManager towerManager;
    TowerManagerProxy towerManagerProxy;
    BuildingUI buildingUI;

    std::filesystem::path currentMapPath;
    std::filesystem::path currentEnemiesPath;
    int currentDecorAmount;

    btn::PlayButton waveButton;
    sf::Text waveCounter;

    bool paused{};
    PauseMenu pauseMenu;
public:
    GameScreen(IScreenStateMachine* _machine);

    void update() override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void setCurrentMap(const std::filesystem::path& _mapPath, int decorAmount) {map.loadMap(_mapPath, decorAmount); currentMapPath = _mapPath; currentDecorAmount = decorAmount;}

    void setCurrentEnemies(const std::filesystem::path& _enemyPath) {waveManager.loadEnemies(_enemyPath); currentEnemiesPath = _enemyPath;}
private:
    /// @brief  zwraca prawda jesli wyszlo z gry
    bool managePauseMenu();

    void resetLevel();
};
