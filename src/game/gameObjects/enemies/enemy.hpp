#pragma once
#include <SFML/Graphics.hpp>

/// @class klasa abstrakcyjna do przeciwnikow
class Enemy : public sf::Drawable, public sf::Transformable
{
    sf::Sprite sprite;
public:
    Enemy(const sf::Texture& _texture);

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect{getPosition(), sprite.getGlobalBounds().size};}

    /// @brief nalezy wywolywac to w glownej petli
    virtual void update();
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        target.draw(sprite, states);
    }
};
