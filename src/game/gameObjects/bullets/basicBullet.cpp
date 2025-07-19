#include "basicBullet.hpp"

BasicBullet::BasicBullet(Enemy* _target)
    : sprite(util::AssetLoader::get().basicBullet), 
    speed(12.f), target{_target}, damage(10)
{
    setOrigin(getGlobalBounds().getCenter());
    setScale({0.5f,0.5f});
}

void BasicBullet::update()
{
    move(moveBy);

    hitTimer--;
}

void BasicBullet::launch(sf::Vector2f from, sf::Vector2f where)
{
    // wektor ruchu
    moveBy = where - from;
    hitTimer = static_cast<int>(moveBy.length() / speed);
    if(moveBy != sf::Vector2f{})
        moveBy = moveBy.normalized() * speed;
    setPosition(from);
    setRotation(moveBy.angle());
}

void BasicBullet::hitTarget()
{
    if(hitTimer > 0)
        return; // jeszcze nie dolecial

    target->dealDamage(getDamage());
    shouldDelete_ = true;
}
