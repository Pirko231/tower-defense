#pragma once
#include "turretInterface.hpp"
#include "../bullets/basicBullet.hpp"
#include "../enemies/enemy.hpp"


class Turret : public ITurret
{
    sf::Sprite sprite;

    float range{};
protected:
    std::vector<BasicBullet> bullets;

    int maxCooldown{100};
    int cooldown{};
public:
    void update() override;

    float getRange() const override {return range;}

    sf::FloatRect getGlobalBounds() const override {return sf::FloatRect{getPosition(), sprite.getGlobalBounds().size};}

    virtual void shoot(sf::Vector2f from, Enemy* target) = 0;
protected:
    explicit Turret(const sf::Texture& _texture, float _range)
        : sprite(_texture), range{_range}, cooldown{maxCooldown}
    {}

    void setRange(float _range) override {range = _range;}

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        for(auto& bullet : bullets)
            target.draw(bullet);
        target.draw(sprite, states);
    }
};