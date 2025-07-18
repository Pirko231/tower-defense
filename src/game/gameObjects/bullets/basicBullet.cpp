#include "basicBullet.hpp"

BasicBullet::BasicBullet(Enemy* _target)
    : sprite(util::AssetLoader::get().basicBullet), 
    speed(2.f), target{_target}, damage(10), timerMax{480}, timer{timerMax}
{
}

void BasicBullet::update()
{
    move(moveBy);

    timer--;
    hitTimer--;
}

void BasicBullet::launch(sf::Vector2f from, sf::Vector2f where)
{
    // wektor ruchu
    moveBy = where - from;
    hitTimer = (int)moveBy.length();
    if(moveBy != sf::Vector2f{})
        moveBy = moveBy.normalized();
    setPosition(from);
    setRotation(moveBy.angle());
}

void BasicBullet::hitTarget()
{
    if(hitTimer > 0)
        return; // jeszcze nie dolecial

    target->dealDamage(getDamage());
    timer = -1; // kasujemy obiekt
}
