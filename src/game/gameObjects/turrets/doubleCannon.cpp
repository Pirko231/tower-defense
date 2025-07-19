#include "doubleCannon.hpp"

DoubleCannon::DoubleCannon()
    : Turret(util::AssetLoader::get().doubleCannon, 200.f)
{
}

void DoubleCannon::shoot(sf::Vector2f from, Enemy * target)
{
    cooldown--;
    if(cooldown > 0)
        return; // cooldown nie minal
    cooldown = maxCooldown;
    
    BasicBullet bullet{target};
    bullet.launch(from, target->getPosition());
    bullets.push_back(bullet);
}
