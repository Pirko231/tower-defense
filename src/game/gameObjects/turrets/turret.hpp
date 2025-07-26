#pragma once
#include "../bullets/basicBullet.hpp"
#include "../enemies/enemy.hpp"
#include "bulletManagerInterface.hpp"


class Turret : public sf::Drawable, public sf::Transformable
{
public:
    struct Stats
    {
        float range{};
        float damage{};
    };
private:
    sf::Sprite sprite;
    int upgradePrice{};
protected:
    IBulletManager* bulletManager{};

    
    int maxCooldown{100};
    int cooldown{};
    Stats stats;
public:
    virtual void update();

    /// @brief oblicza i zwraca obrazenia na klatke
    virtual float getDPS() const {return (float)stats.damage / (float)maxCooldown;}

    float getRange() const {return stats.range;}

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect{getPosition(), sprite.getGlobalBounds().size};}

    virtual void shoot(sf::Vector2f from, Enemy* target) = 0;

    int getUpgradePrice() const {return upgradePrice;}

    /// @brief mnozy statyskyki o doubler
    void upgrade(Stats statsDoubler, float priceDoubler)
    {
        stats.range *= statsDoubler.range;
        stats.damage *= statsDoubler.damage;
        upgradePrice = (float)upgradePrice * priceDoubler;
    }
protected:
    explicit Turret(const sf::Texture& _texture, IBulletManager* _bulletManager, float _range, int _damage)
        : sprite(_texture), bulletManager(_bulletManager),  cooldown{maxCooldown}, stats(_range, _damage)
    {}

    void setRange(float _range) {stats.range = _range;}

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        target.draw(sprite, states);
    }
};