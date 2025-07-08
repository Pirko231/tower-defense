#pragma once
#include "../gameObjects/enemies/enemy.hpp"

class IEnemyFactory
{
public:
    IEnemyFactory() = default;

    virtual std::unique_ptr<Enemy> create() const = 0;
};
