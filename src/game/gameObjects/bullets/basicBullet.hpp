#pragma once
#include "bulletInterface.hpp"
#include "base.hpp"

class BasicBullet : public IBullet
{
    sf::Sprite sprite;
    sf::Vector2f moveBy;
    float speed{};

    int timerMax;
    int timer;
    int hitTimer{};
public:
    BasicBullet(float _speed);

    void update() override;

    void launch(sf::Vector2f from, sf::Vector2f where) override;

    sf::FloatRect getGlobalBounds() const override {return sf::FloatRect{getPosition(), sprite.getGlobalBounds().size};}
};