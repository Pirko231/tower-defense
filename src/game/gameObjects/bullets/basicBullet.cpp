#include "basicBullet.hpp"

namespace
{
    constexpr float speed = 12.f;
}

BasicBullet::BasicBullet(Enemy* _target, int _damage)
    : Bullet(util::AssetLoader::get().basicBullet, ::speed, _damage, _target)
{
    setOrigin(getGlobalBounds().getCenter());
    setScale({0.5f,0.5f});
}

void BasicBullet::update()
{
    Bullet::update();

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
