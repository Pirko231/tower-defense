#pragma once
#include <SFML/Graphics.hpp>

#include "pressed.hpp"
#include "game/buildingui.hpp"
#include "game/gameObjects/managers/towermanagerproxy.hpp"
#include "game/map.hpp"

class Program
{
    sf::RenderWindow* window;
    Pressed pressed;

    Map map;
    BuildingUI buildingUI;
    TowerManager towerManager;
    TowerManagerProxy towerManagerProxy;
public:
    Program();

    ~Program()
    {
        delete window;
    }
    [[nodiscard]] bool running() const {return window->isOpen();}
    void handleEvents();
    void update();
    void display();
};
