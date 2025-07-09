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

    virtual bool hasReachedDestination();

    /// @brief zmienia currentChecpoint i wylicza moveBy
    virtual void nextDestination();
private:

    sf::FloatRect calculateCheckpointsHitbox() const;
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        sf::RectangleShape shape(calculateCheckpointsHitbox().size);
        shape.setPosition(calculateCheckpointsHitbox().position);
        target.draw(shape);

        target.draw(sprite, states);
    }
};
