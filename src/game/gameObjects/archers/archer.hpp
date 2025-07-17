#pragma once
#include "archerInterface.hpp"


class Archer : public IArcher
{
    sf::Sprite sprite;

    float range{};
public:
    explicit Archer(const sf::Texture& _texture)
        : sprite(_texture)
    {

    }

    Archer(const Archer& archer) = default;
    Archer(Archer&&) = default;
    ~Archer() override = default;

    void setRange(float _range) override{ range = _range;}

    float getRange() const override {return range;}

    sf::FloatRect getGlobalBounds() const override {return sf::FloatRect{getPosition(), sprite.getGlobalBounds().size};}

    void shoot(sf::Vector2f where) override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        target.draw(sprite, states);
    }
};