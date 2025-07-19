#pragma once
#include "turret.hpp"

class DoubleCannon : public Turret
{
public:
    DoubleCannon();
    void shoot(sf::Vector2f, Enemy*) override;
};