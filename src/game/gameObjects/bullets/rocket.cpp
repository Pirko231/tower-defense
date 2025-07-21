#include "rocket.hpp"

Rocket::Rocket(Enemy *_target, int _damage)
    : sprite(util::AssetLoader::get().basicBullet), 
    speed(1.f), target{_target}, damage(_damage)
{
    setOrigin(getGlobalBounds().getCenter());
    //setScale({0.5f,0.5f});
}


void Rocket::update()
{
    move(moveBy);
    
    //moveBy = getPosition() - target->getGlobalBounds().getCenter();
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
    if(!getGlobalBounds().findIntersection(target->getGlobalBounds()))
        return;

    target->dealDamage(getDamage());
    shouldDelete_ = true;
}
