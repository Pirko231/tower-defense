#pragma once
#include "../gameObjects/enemies/enemy.hpp"
#include "../checkpoint.hpp"

class IEnemyFactory
{
public:
    IEnemyFactory() = default;

    virtual std::unique_ptr<Enemy> create(Checkpoint::Iterator checkpoint) const = 0;
};
