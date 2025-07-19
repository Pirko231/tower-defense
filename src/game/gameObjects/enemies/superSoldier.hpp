#pragma once
#include "enemy.hpp"

class SuperSoldier : public Enemy
{
public:
    SuperSoldier(Checkpoint::Iterator);
};