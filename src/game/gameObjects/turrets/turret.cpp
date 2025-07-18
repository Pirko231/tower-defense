#include "turret.hpp"

void Turret::update()
{

    std::remove_if(bullets.begin(), bullets.end(), [](BasicBullet& b)->bool{b.update(); return b.shouldDelete();});

    /*for(auto bullet = bullets.begin(); bullet != bullets.end(); bullet++)
    {
        bullet->update();
        if(bullet->shouldDelete())
        {
            bullet = bullets.erase(bullet);
        }
    }*/
}

void Turret::shoot(sf::Vector2f from, Enemy *target)
{
    BasicBullet bullet{target};
    bullet.launch(from, target->getPosition());
    bullets.push_back(bullet);
}
