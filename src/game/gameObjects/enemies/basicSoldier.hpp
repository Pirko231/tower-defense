#pragma once
#include "enemy.hpp"

class BasicSoldier : public Enemy
{
public:
    BasicSoldier(Checkpoint::Iterator _checkpoint);
};