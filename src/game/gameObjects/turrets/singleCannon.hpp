#pragma once
#include "turret.hpp"

class SingleCannon : public Turret
{
public:
    SingleCannon();
    void shoot(sf::Vector2f, Enemy*) override;
};