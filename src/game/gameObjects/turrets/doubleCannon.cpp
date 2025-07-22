#include "doubleCannon.hpp"

namespace
{
    constexpr float range = 250.f;
    constexpr int damage = 14;
}

DoubleCannon::DoubleCannon(IBulletManager* _bulletManager)
    : Turret(util::AssetLoader::get().doubleCannon, _bulletManager, ::range, ::damage)
{
    maxCooldown = 80;
}

void DoubleCannon::shoot(sf::Vector2f from, Enemy * target)
{
    cooldown--;
    cooldown2--;
    
    barrelOneShoot(from, target);
    barrelSecondShoot(from,target);
}

void DoubleCannon::barrelOneShoot(sf::Vector2f from, Enemy *target)
{
    if(cooldown > 0)
        return; // cooldown nie minal
    cooldown = maxCooldown;

    bulletManager->launchBasicBullet(from, target->getPosition(), target, damage);
}

void DoubleCannon::barrelSecondShoot(sf::Vector2f from, Enemy *target)
{
    if(cooldown2 > 0)
        return; // cooldown nie minal
    cooldown2 = maxCooldown2;


    bulletManager->launchBasicBullet(from, target->getPosition(), target, damage);
}
