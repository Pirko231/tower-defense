#pragma once
#include <SFML/Graphics.hpp>
#include "game/gameObjects/managers/towermanager.hpp"

class Program
{
    sf::RenderWindow* window;

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
