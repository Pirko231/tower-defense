#pragma once
#include  <SFML/Graphics.hpp>

class ITurret : public sf::Transformable, public sf::Drawable
{
public:
    virtual void shoot(sf::Vector2f where) = 0;

    virtual void setRange(float) = 0;

    virtual sf::FloatRect getGlobalBounds() const = 0;

    virtual float getRange() const = 0;
};
