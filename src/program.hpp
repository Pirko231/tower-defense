#pragma once
#include <SFML/Graphics.hpp>
#include "game/gameObjects/managers/towermanager.hpp"
#include "game/map.hpp"

class Program
{
    sf::RenderWindow* window;

    Map map;
    TowerManager towerManager;
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
