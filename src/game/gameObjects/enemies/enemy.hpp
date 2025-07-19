#pragma once
#include <SFML/Graphics.hpp>
#include "../../checkpoint.hpp"
#include "../healthbar.hpp"

/// @class klasa abstrakcyjna do przeciwnikow
/// @brief wzorzec metoda szablonowa (funkcja update)
class Enemy : public sf::Drawable, public sf::Transformable
{
    int maxHealth{100};
    int health{maxHealth};
    HealthBar healthBar{maxHealth};
    float speed{};

    int damage{};
    int moneyValue{};
protected:
    sf::Sprite sprite;

    Checkpoint::Iterator currentCheckpoint;

    sf::Vector2f moveBy{};
protected:
    Enemy(const sf::Texture& _texture, Checkpoint::Iterator _checkpoint, int _moneyValue, int _maxHealth, int _damage, float _speed);
public:
    sf::FloatRect getGlobalBounds() const {return sf::FloatRect{getPosition(), sprite.getGlobalBounds().size};}

    /// @brief nalezy wywolywac to w glownej petli
    void update();

    bool hasNext() const {return currentCheckpoint.hasNext();}

    void dealDamage(int damageToDeal) {health -= damageToDeal;}

    void setDamage(int _damage) {damage = _damage;}

    int getDamage() const {return damage;}

    int getMoney() const {return moneyValue;}

    bool shouldDelete() const {return health <= 0;}

    /// @brief przelicza moveBy i ustawia go
    void calculateMoveBy();

    /// @brief sprawdza kolizje z checkpointem
    /// @return czy koliduje
    virtual bool hasReachedDestination() const;

    /// @brief zmienia currentChecpoint i wylicza moveBy
    virtual void nextDestination();
protected:

    sf::FloatRect calculateCheckpointsHitbox() const;
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        target.draw(sprite, states);
        target.draw(healthBar);
    }
};
