#include "rocketLauncher.hpp"

RocketLauncher::RocketLauncher(IBulletManager* _bulletManager)
    : Turret(util::AssetLoader::get().rocketLauncher, _bulletManager, "resources/data/turrets/rocketLauncher.xml")
{
    //maxCooldown = 400;
}

void RocketLauncher::update()
{
}

void RocketLauncher::shoot(sf::Vector2f from, Enemy *target)
{
    cooldown--;
    if(cooldown > 0)
        return; // cooldown nie minal
    cooldown = maxCooldown;
    
    bulletManager->launchRocket(from, target->getPosition(), target, getStats().damage);
}