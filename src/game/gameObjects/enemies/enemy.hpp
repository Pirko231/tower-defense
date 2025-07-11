#pragma once
#include <SFML/Graphics.hpp>
#include "../../map.hpp"
#include "../healthbar.hpp"

/// @class klasa abstrakcyjna do przeciwnikow
/// @brief wzorzec metoda szablonowa (funkcja update)
class Enemy : public sf::Drawable, public sf::Transformable
{
    sf::Sprite sprite;

    Checkpoint::Iterator currentCheckpoint;

    sf::Vector2f moveBy{};

    int maxHealth{100};
    int health{maxHealth};
    HealthBar healthBar{maxHealth};
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
#ifdef DEBUG
        sf::RectangleShape shape(calculateCheckpointsHitbox().size);
        shape.setPosition(calculateCheckpointsHitbox().position);
        target.draw(shape);

        sf::RectangleShape hitbox{getGlobalBounds().size};
        hitbox.setPosition(getPosition() - getGlobalBounds().size / 2.f);
        hitbox.setFillColor(sf::Color{0,0,255,100});
        target.draw(hitbox);
#endif
        target.draw(sprite, states);
        target.draw(healthBar);
    }
};
