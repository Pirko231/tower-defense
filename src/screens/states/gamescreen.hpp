#pragma once
#include "pressed.hpp"
#include "screenstate.hpp"
#include "managers/towermanagerproxy.hpp"
#include "managers/enemymanager.hpp"
#include "../map.hpp"
#include "../../game/buildingui.hpp"

class GameScreen : public ScreenState
{
    int money{100};
    Map map;
    TowerManager towerManager;
    TowerManagerProxy towerManagerProxy;
    BuildingUI buildingUI;
    EnemyManager enemyManager;
public:
    GameScreen(IScreenStateMachine* _machine);

    void update() override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void setCurrentMap(const std::filesystem::path& _mapPath) {map.loadMap(_mapPath); enemyManager.loadCheckPoints();}
};
