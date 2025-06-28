#pragma once
#include "../gameObjects/towers/tower.hpp"

enum class TowerType
{
    Archer
};

class ITowerFactory
{
public:
    virtual ~ITowerFactory() = default;

    virtual std::unique_ptr<Tower> create() = 0;
};
