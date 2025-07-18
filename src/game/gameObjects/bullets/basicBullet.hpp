#pragma once
#include "bulletInterface.hpp"
#include "../enemies/enemy.hpp"
#include "base.hpp"

class BasicBullet : public IBullet
{
    sf::Sprite sprite;
    sf::Vector2f moveBy;
    float speed{};
    Enemy* target{};

    int damage;
    int timerMax;
    int timer;
    int hitTimer{};
public:
    BasicBullet(Enemy* _target);

    void update() override;

    void launch(sf::Vector2f from, sf::Vector2f where) override;

    sf::FloatRect getGlobalBounds() const override {return sf::FloatRect{getPosition(), sprite.getGlobalBounds().size};}

    Enemy* getTarget() const override {return target;}

    int getDamage() const override {return damage;}

    bool shouldDelete() const override {return timer <= 0;}

    bool hasHitTarget() const override {return hitTimer <= 0;}
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        target.draw(sprite, states);
    }
};