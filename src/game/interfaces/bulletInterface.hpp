#pragma once
#include <SFML/Graphics.hpp>
#include "../gameObjects/enemies/enemy.hpp"

class IBullet : public sf::Drawable, public sf::Transformable
{
public:
    virtual void update() = 0;

    virtual void launch(sf::Vector2f from, sf::Vector2f where) = 0;

    virtual sf::FloatRect getGlobalBounds() const = 0;

    virtual int getDamage() const = 0;

    virtual Enemy* getTarget() const = 0;

    virtual bool shouldDelete() const = 0;

    /// @brief sprawdza czy trafil w cel, jesli tak to wykonuje cala prace (zadanie obraze)
    /// potem oznacza sie jako pocisk do usuniecia
    virtual void hitTarget() = 0;
};