#pragma once
#include "turret.hpp"

class MachineGun : public Turret
{
public:
    MachineGun(IBulletManager* _bulletManager);
    void shoot(sf::Vector2f, Enemy*) override;
};