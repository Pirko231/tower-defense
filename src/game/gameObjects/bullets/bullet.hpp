#pragma once
#include <SFML/Graphics.hpp>
#include "../enemies/enemy.hpp"

class Bullet : public sf::Drawable, public sf::Transformable
{
    sf::Sprite sprite;
    int damage;
protected:
    Enemy* target{};
    sf::Vector2f moveBy{};
    float speed{};

    bool shouldDelete_{};
public:
    virtual void update();

    virtual void launch(sf::Vector2f from, sf::Vector2f where);

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect{getPosition(), sprite.getGlobalBounds().size};}

    Enemy* getTarget() const {return target;}

    void setTarget(Enemy* _target) {target = _target;}

    int getDamage() const {return damage;}

    bool shouldDelete() const {return shouldDelete_;}

    void setDelete(bool value) {shouldDelete_ = value;}

    /// @brief sprawdz czy pocisk obecnie trafil w cel
    virtual bool hasHitTarget() const = 0;

    /// @brief sprawdza czy trafil w cel, jesli tak to wykonuje cala prace (zadanie obraze)
    /// potem oznacza sie jako pocisk do usuniecia
    virtual void hitTarget() = 0;

protected:
    Bullet(const sf::Texture& texture, float _speed, int _damage, Enemy* _target);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        target.draw(sprite, states);
    }
};