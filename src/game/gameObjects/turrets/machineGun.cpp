#include "machineGun.hpp"

namespace
{
    constexpr float range = 180.f;
    constexpr int damage = 4;
}

MachineGun::MachineGun(IBulletManager* _bulletManager)
    : Turret(util::AssetLoader::get().machineGun, _bulletManager, ::range, ::damage)
{
    maxCooldown = 10;
    cooldown = maxCooldown;
}

void MachineGun::shoot(sf::Vector2f from, Enemy * target)
{
    cooldown--;
    if(cooldown > 0)
        return;
    cooldown = maxCooldown;

    bulletManager->launchBasicBullet(from, target->getPosition(), target, damage);
    
}
