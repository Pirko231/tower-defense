#pragma once
#include "pressed.hpp"
#include "screenstate.hpp"
#include "managers/towermanagerproxy.hpp"
#include "../map.hpp"
#include "../../game/buildingui.hpp"

class GameScreen : public ScreenState
{
    Pressed& pressed;
    sf::RenderWindow* window{};

    Map map;
    BuildingUI buildingUI;
    TowerManager towerManager;
    TowerManagerProxy towerManagerProxy;
public:
    GameScreen(Pressed& _pressed, sf::RenderWindow* window);

    void update() override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
