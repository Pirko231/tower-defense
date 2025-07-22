#pragma once
#include "../gameObjects/enemies/enemy.hpp"

class IBulletManager
{
public:
    virtual void launchBasicBullet(sf::Vector2f from, sf::Vector2f where, Enemy* target, int damage) = 0;

    virtual void launchRocket(sf::Vector2f from, sf::Vector2f where, Enemy* target, int damage) = 0;
};