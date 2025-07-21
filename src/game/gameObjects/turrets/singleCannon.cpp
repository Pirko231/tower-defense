#include "singleCannon.hpp"

namespace
{
    constexpr float range = 400.f;
    constexpr int damage = 15;
}

SingleCannon::SingleCannon()
    : Turret(util::AssetLoader::get().singleCannon, ::range, ::damage)
{
}

void SingleCannon::shoot(sf::Vector2f from, Enemy *target)
{
    cooldown--;
    if(cooldown > 0)
        return; // cooldown nie minal
    cooldown = maxCooldown;
    

    BasicBullet bullet{target, damage};
    bullet.launch(from, target->getPosition());
    bullets.push_back(bullet);
}