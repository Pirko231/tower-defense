#include "doubleCannon.hpp"

DoubleCannon::DoubleCannon()
    : Turret(util::AssetLoader::get().doubleCannon, 200.f)
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

    BasicBullet bullet{target};
    bullet.launch(from, target->getPosition());
    bullets.push_back(bullet);
}

void DoubleCannon::barrelSecondShoot(sf::Vector2f from, Enemy *target)
{
    if(cooldown2 > 0)
        return; // cooldown nie minal
    cooldown2 = maxCooldown2;

    BasicBullet bullet{target};
    bullet.launch(from, target->getPosition());
    bullets.push_back(bullet);
}
