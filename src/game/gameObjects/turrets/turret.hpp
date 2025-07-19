#pragma once
#include "../bullets/basicBullet.hpp"
#include "../enemies/enemy.hpp"


class Turret : public sf::Drawable, public sf::Transformable
{
    sf::Sprite sprite;

    float range{};
protected:
    std::vector<BasicBullet> bullets;

    int maxCooldown{100};
    int cooldown{};
    int damage{};
public:
    void update();

    float getRange() const {return range;}

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect{getPosition(), sprite.getGlobalBounds().size};}

    virtual void shoot(sf::Vector2f from, Enemy* target) = 0;
protected:
    explicit Turret(const sf::Texture& _texture, float _range, int _damage)
        : sprite(_texture), range{_range}, cooldown{maxCooldown}, damage{_damage}
    {}

    void setRange(float _range) {range = _range;}

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        for(auto& bullet : bullets)
            target.draw(bullet);
        target.draw(sprite, states);
    }
};