#pragma once
#include "enemy.hpp"


class EliteSoldier : public Enemy
{
public:
    EliteSoldier(Checkpoint::Iterator checkpoint);
};