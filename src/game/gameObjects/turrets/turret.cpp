#include "turret.hpp"

void Turret::update()
{
    std::remove_if(bullets.begin(), bullets.end(), [](BasicBullet& b)->bool{return b.shouldDelete();});
    for(auto& bullet : bullets)
    {
        bullet.update();
        bullet.hitTarget();
    }
}

void Turret::shoot(sf::Vector2f from, Enemy *target)
{
    BasicBullet bullet{target};
    bullet.launch(from, target->getPosition());
    bullets.push_back(bullet);
}
