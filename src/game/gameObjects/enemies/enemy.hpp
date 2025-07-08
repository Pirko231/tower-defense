#pragma once
#include <SFML/Graphics.hpp>

class Enemy : public sf::Drawable, public sf::Transformable
{
    sf::Sprite sprite;
public:
    Enemy(const sf::Texture& _texture);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        target.draw(sprite, states);
    }
};
