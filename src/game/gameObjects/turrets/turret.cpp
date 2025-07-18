#include "turret.hpp"

void Turret::update()
{
    for(auto& bullet : bullets)
        bullet.update();
}

void Turret::shoot(sf::Vector2f from, Enemy *target)
{
    BasicBullet bullet{target};
    bullet.launch(from, target->getPosition());
    bullets.push_back(bullet);
}
