#pragma once
#include  <SFML/Graphics.hpp>
#include "../gameObjects/enemies/enemy.hpp"

class ITurret : public sf::Transformable, public sf::Drawable
{
public:
    virtual void shoot(sf::Vector2f from, Enemy* what) = 0;

    virtual void update() = 0;

    virtual void setRange(float) = 0;

    virtual sf::FloatRect getGlobalBounds() const = 0;

    virtual float getRange() const = 0;
};
