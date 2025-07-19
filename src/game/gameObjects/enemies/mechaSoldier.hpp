#pragma once
#include "enemy.hpp"


class MechaSoldier : public Enemy
{
public:
    MechaSoldier(Checkpoint::Iterator checkpoint);
};