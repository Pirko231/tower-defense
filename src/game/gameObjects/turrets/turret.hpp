#pragma once
#include "../bullets/basicBullet.hpp"
#include "../enemies/enemy.hpp"
#include "bulletManagerInterface.hpp"


class Turret : public sf::Drawable, public sf::Transformable
{
    sf::Sprite sprite;
    float range{};
protected:
    IBulletManager* bulletManager{};

    int maxCooldown{100};
    int cooldown{};
    int damage{};
public:
    virtual void update();

    /// @brief oblicza i zwraca obrazenia na klatke
    virtual float getDPS() const {return (float)damage / (float)maxCooldown;}

    float getRange() const {return range;}

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect{getPosition(), sprite.getGlobalBounds().size};}

    virtual void shoot(sf::Vector2f from, Enemy* target) = 0;
protected:
    explicit Turret(const sf::Texture& _texture, IBulletManager* _bulletManager, float _range, int _damage)
        : sprite(_texture), range{_range}, bulletManager(_bulletManager),  cooldown{maxCooldown}, damage{_damage}
    {}

    void setRange(float _range) {range = _range;}

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        target.draw(sprite, states);
    }
};