#include "bullet.hpp"

Bullet::Bullet(const sf::Texture &texture, float _speed, int _damage, Enemy *_target)
    :  sprite(texture), damage(_damage), target(_target), speed(_speed)
{
}

void Bullet::update()
{
    move(moveBy);
}

void Bullet::launch(sf::Vector2f from, sf::Vector2f where)
{
    // wektor ruchu
    moveBy = where - from;
    if(moveBy != sf::Vector2f{})
        moveBy = moveBy.normalized() * speed;
    setPosition(from);
    setRotation(moveBy.angle());
}
