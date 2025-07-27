#include "machineGun.hpp"

namespace
{
    constexpr float range = 1.f;
    constexpr int damage = 6;
}

MachineGun::MachineGun(IBulletManager* _bulletManager)
    : Turret(util::AssetLoader::get().machineGun, _bulletManager, "resources/data/turrets/singleCannon.xml")
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

    bulletManager->launchBasicBullet(from, target->getPosition(), target, getStats().damage);
    
}
