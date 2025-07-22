#pragma once
#include "turret.hpp"

class SingleCannon : public Turret
{
public:
    SingleCannon(IBulletManager* _bulletManager);
    void shoot(sf::Vector2f, Enemy*) override;
};