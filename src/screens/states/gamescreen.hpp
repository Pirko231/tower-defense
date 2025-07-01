#pragma once
#include "pressed.hpp"
#include "screenstate.hpp"
#include "managers/towermanagerproxy.hpp"
#include "../map.hpp"
#include "../../game/buildingui.hpp"

class GameScreen : public ScreenState
{
    Map map;
    BuildingUI buildingUI;
    TowerManager towerManager;
    TowerManagerProxy towerManagerProxy;
public:
    GameScreen(IScreenStateMachine* _machine);

    void update() override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void setCurrentMap(const std::filesystem::path& _mapPath) {map.loadMap(_mapPath);}
};
