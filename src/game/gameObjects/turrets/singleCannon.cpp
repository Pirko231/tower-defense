#include "singleCannon.hpp"

SingleCannon::SingleCannon(IBulletManager* _bulletManager)
    : Turret(util::AssetLoader::get().singleCannon, _bulletManager , "resources/data/turrets/singleCannon.xml")
{
}

void SingleCannon::shoot(sf::Vector2f from, Enemy *target)
{
    cooldown--;
    if(cooldown > 0)
        return; // cooldown nie minal
    cooldown = maxCooldown;
    
    bulletManager->launchBasicBullet(from, target->getPosition(), target, getStats().damage);
}