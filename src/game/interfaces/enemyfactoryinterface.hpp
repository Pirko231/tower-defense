#pragma once
#include "../enemies/enemy.hpp"

class EnemyFactoryInterface
{
public:
    EnemyFactoryInterface() = default;

    virtual std::unique_ptr<Enemy> create() const = 0;
};
