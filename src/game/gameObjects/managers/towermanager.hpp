#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "towerFactoryInterface.hpp"
#include "factories/archerFactory.hpp"


class TowerManager
{
    std::vector<std::unique_ptr<Tower>> towers;
public:
    TowerManager() = default;

    void addTower(sf::Vector2i where, TowerType what);

    void update();

    void display(sf::RenderWindow* window);
};
