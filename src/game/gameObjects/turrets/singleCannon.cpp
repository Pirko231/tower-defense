#include "singleCannon.hpp"

namespace
{
    constexpr float range = 4.f;
    constexpr int damage = 25;
}

SingleCannon::SingleCannon(IBulletManager* _bulletManager)
    : Turret(util::AssetLoader::get().singleCannon, _bulletManager , ::range, ::damage)
{
}

void SingleCannon::shoot(sf::Vector2f from, Enemy *target)
{
    cooldown--;
    if(cooldown > 0)
        return; // cooldown nie minal
    cooldown = maxCooldown;
    
    bulletManager->launchBasicBullet(from, target->getPosition(), target, damage);
}