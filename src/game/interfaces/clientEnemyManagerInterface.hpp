#pragma once
#include "../gameObjects/enemies/enemy.hpp"

class IClientEnemyManager
{
public:
    virtual Enemy* getTheMostFarEnemy(sf::FloatRect area) = 0;
};