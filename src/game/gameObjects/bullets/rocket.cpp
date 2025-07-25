#include "rocket.hpp"

namespace
{
    constexpr float speed = 6.f;
}

Rocket::Rocket(Enemy *_target, int _damage)
    : Bullet(util::AssetLoader::get().rocket, ::speed, _damage, _target)
{
    setOrigin(getGlobalBounds().getCenter());
    setScale({0.5f,0.5f});
}


void Rocket::update()
{
    move(moveBy);
    
    moveBy = target->getGlobalBounds().getCenter() - getPosition();
    if(moveBy != sf::Vector2f{})
    {
        moveBy = moveBy.normalized() * speed;
        if(moveBy != sf::Vector2f{})
            setRotation(moveBy.angle());
    }
}

void Rocket::launch(sf::Vector2f from, sf::Vector2f where)
{
    // wektor ruchu
    moveBy = where - from;
    if(moveBy != sf::Vector2f{})
        moveBy = moveBy.normalized() * speed;
    setPosition(from);
    setRotation(moveBy.angle());
}

void Rocket::hitTarget()
{
    target->dealDamage(getDamage());
    shouldDelete_ = true;
}
