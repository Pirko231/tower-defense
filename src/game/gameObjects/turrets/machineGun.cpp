#include "machineGun.hpp"

namespace
{
    constexpr float range = 180.f;
    constexpr int damage = 4;
}

MachineGun::MachineGun()
    : Turret(util::AssetLoader::get().machineGun, ::range, ::damage)
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
    
    BasicBullet bullet{target, damage};
    bullet.launch(from, target->getPosition());
    bullets.push_back(bullet);
}
