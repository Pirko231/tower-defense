#pragma once
#include "turret.hpp"

class DoubleCannon : public Turret
{
    int maxCooldown2{80};
    int cooldown2{maxCooldown - 15}; // cooldown2 odpowiada za drugi strzal
public:
    DoubleCannon(IBulletManager* _bulletManager);
    void shoot(sf::Vector2f, Enemy*) override;

    float getDPS() const override {return Turret::getDPS() + ((float)stats.damage / (float)maxCooldown2);}
private:
    /// @brief pierwszy strzal
    void barrelOneShoot(sf::Vector2f from, Enemy * target);

    /// @brief drugi strzal
    void barrelSecondShoot(sf::Vector2f from, Enemy * target);
};