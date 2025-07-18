#pragma once
#include <SFML/Graphics.hpp>
#include "../enemies/enemy.hpp"

class IBullet : public sf::Drawable, public sf::Transformable
{
public:
    virtual void update() = 0;

    virtual void launch(sf::Vector2f from, sf::Vector2f where) = 0;

    virtual sf::FloatRect getGlobalBounds() const = 0;

    virtual int getDamage() const = 0;



    virtual bool shouldDelete() const = 0;

    virtual bool hitTarget() const = 0;
};