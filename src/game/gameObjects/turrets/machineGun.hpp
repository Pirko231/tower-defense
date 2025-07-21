#pragma once
#include "turret.hpp"

class MachineGun : public Turret
{
public:
    MachineGun();
    void shoot(sf::Vector2f, Enemy*) override;
};