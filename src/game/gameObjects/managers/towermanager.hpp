#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "towerFactoryInterface.hpp"
#include "factories/archerFactory.hpp"
#include "../map.hpp"


class TowerManager
{
    friend class TowerManagerProxy;

    std::vector<std::unique_ptr<Tower>> towers;
    Map* map{};
public:
    explicit TowerManager(Map* _map) : map(_map)
    {}

    void update();

    void display(sf::RenderWindow* window);
private:
    void addTower(sf::Vector2i where, TowerType what);
};
