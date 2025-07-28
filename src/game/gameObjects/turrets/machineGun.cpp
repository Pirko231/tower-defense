#include "machineGun.hpp"

MachineGun::MachineGun(IBulletManager* _bulletManager)
    : Turret(util::AssetLoader::get().machineGun, _bulletManager, "resources/data/turrets/machineGun.xml")
{
    //maxCooldown = 10;
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
