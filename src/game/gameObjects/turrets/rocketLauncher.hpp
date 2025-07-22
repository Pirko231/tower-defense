#pragma once
#include "turret.hpp"
#include "../bullets/rocket.hpp"

class RocketLauncher : public Turret
{
public:
    RocketLauncher(IBulletManager* _bulletManager);
    void update() override;
    void shoot(sf::Vector2f, Enemy*) override;
};