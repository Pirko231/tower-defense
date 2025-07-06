#pragma once
#include  "archerInterface.hpp"
#include <memory>

enum class TowerType
{
    Archer = 0
};

class Tower : public sf::Drawable, public sf::Transformable
{
    sf::Sprite sprite;
    std::unique_ptr<IArcher> archer;

    TowerType type;
public:
    Tower(const sf::Texture& towerTexture, std::unique_ptr<IArcher>&& _archer, TowerType _type)
        : sprite(towerTexture), archer(std::move(_archer)), type(_type)
    {

    }
    ~Tower() override = default;

    Tower(Tower& tower)
        : sprite(tower.sprite), archer(std::move(tower.archer))
    {}

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect(getPosition(), sprite.getGlobalBounds().size);}

    TowerType getType() const {return type;}

    void update();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        target.draw(sprite, states);

        target.draw(*archer, states);
    }
};
