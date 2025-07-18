#include "turret.hpp"

void Turret::update()
{
    std::erase_if(bullets, [](const BasicBullet& b)->bool{return b.shouldDelete();});
    for(auto& bullet : bullets)
    {
        bullet.update();
        bullet.hitTarget();
    }
}

void Turret::shoot(sf::Vector2f from, Enemy *target)
{
    cooldown--;
    if(cooldown > 0)
        return; // cooldown nie minal
    cooldown = maxCooldown;
    

    BasicBullet bullet{target};
    bullet.launch(from, target->getPosition());
    bullets.push_back(bullet);
}
