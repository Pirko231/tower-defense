#include "singleCannon.hpp"

SingleCannon::SingleCannon()
    : Turret(util::AssetLoader::get().cannon1, 250.f)
{
}

void SingleCannon::shoot(sf::Vector2f from, Enemy *target)
{
    cooldown--;
    if(cooldown > 0)
        return; // cooldown nie minal
    cooldown = maxCooldown;
    

    BasicBullet bullet{target};
    bullet.launch(from, target->getPosition());
    bullets.push_back(bullet);
}