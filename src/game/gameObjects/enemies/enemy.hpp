#pragma once
#include <SFML/Graphics.hpp>
#include "../../map.hpp"

/// @class klasa abstrakcyjna do przeciwnikow
/// @brief wzorzec metoda szablonowa (funkcja update)
class Enemy : public sf::Drawable, public sf::Transformable
{
    sf::Sprite sprite;

    Checkpoint::Iterator currentCheckpoint;

    sf::Vector2f moveBy{};
public:
    Enemy(const sf::Texture& _texture, Checkpoint::Iterator _checkpoint);

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect{getPosition(), sprite.getGlobalBounds().size};}

    /// @brief nalezy wywolywac to w glownej petli
    void update();

    virtual bool hasReachedDestination() {return (bool)getGlobalBounds().findIntersection(currentCheckpoint->getGlobalBounds());}

    /// @brief zmienia currentChecpoint i wylicza moveBy
    virtual void nextDestination();
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        target.draw(sprite, states);
    }
};
