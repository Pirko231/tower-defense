#pragma once
#include "../gameObjects/towers/tower.hpp"

class ITowerFactory
{
public:
    virtual ~ITowerFactory() = default;

    virtual std::unique_ptr<Tower> create() = 0;
};
