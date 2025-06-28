#pragma once
#include  "archerInterface.hpp"
#include <memory>

class Tower : public sf::Drawable, public sf::Transformable
{
    sf::Sprite sprite;
    std::unique_ptr<IArcher> archer;
public:
    Tower(const sf::Texture& towerTexture, std::unique_ptr<IArcher>&& _archer)
        : sprite(towerTexture), archer(std::move(_archer))
    {

    }
    ~Tower() override = default;

    /*Tower(const Tower& tower)
        : sprite(tower.sprite), archer(tower.archer)
    {}*/

    void update();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        target.draw(sprite, states);

        target.draw(*archer, states);
    }
};
