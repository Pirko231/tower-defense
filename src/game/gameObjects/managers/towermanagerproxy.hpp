#pragma once
#include "towermanager.hpp"

class TowerManager;

class TowerManagerProxy
{
    //friend void TowerManager::addTower(sf::Vector2i, TowerType);

    TowerManager* towerManager{};
public:
    TowerManagerProxy(TowerManager* _towerManager)
        : towerManager(_towerManager)
    {}

    void addTower(sf::Vector2i where, TowerType what);
};
