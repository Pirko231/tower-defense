#include "turret.hpp"

void Turret::shoot(sf::Vector2f where)
{
    sf::Vector2f offset {getPosition() - where};
    if(offset != sf::Vector2f{})
        setRotation(offset.angle());
}
