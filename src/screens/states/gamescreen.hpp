#pragma once
#include "pressed.hpp"
#include "screenstate.hpp"
#include "managers/towermanagerproxy.hpp"
#include "managers/enemymanager.hpp"
#include "managers/wavemanager.hpp"
#include "../map.hpp"
#include "../../game/buildingui.hpp"
#include "../../buttons/playbutton.hpp"

class GameScreen : public ScreenState
{
    int money{100};
    int health{100};
    Map map;
    TowerManager towerManager;
    TowerManagerProxy towerManagerProxy;
    BuildingUI buildingUI;
    EnemyManager enemyManager;
    WaveManager waveManager;

    btn::PlayButton waveButton;
    sf::Text waveCounter;
public:
    GameScreen(IScreenStateMachine* _machine);

    void update() override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void setCurrentMap(const std::filesystem::path& _mapPath) {map.loadMap(_mapPath);}

    void setCurrentEnemies(const std::filesystem::path& _enemyPath) {waveManager.loadEnemies(_enemyPath);}
};
