#pragma once
#include "turretInterface.hpp"
#include "../bullets/basicBullet.hpp"
#include "../enemies/enemy.hpp"


class Turret : public ITurret
{
    sf::Sprite sprite;

    float range{};

    std::vector<BasicBullet> bullets;

    int maxCooldown{100};
    int cooldown{};
public:
    explicit Turret(const sf::Texture& _texture)
        : sprite(_texture), cooldown{maxCooldown}
    {

    }

    void update() override;

    void setRange(float _range) override{ range = _range;}

    float getRange() const override {return range;}

    sf::FloatRect getGlobalBounds() const override {return sf::FloatRect{getPosition(), sprite.getGlobalBounds().size};}

    void shoot(sf::Vector2f from, Enemy* target) override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        for(auto& bullet : bullets)
            target.draw(bullet);
        target.draw(sprite, states);
    }
};