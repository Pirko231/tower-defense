#pragma once
#include <SFML/Graphics.hpp>
#include "../gameObjects/towers/tower.hpp"
#include "towerFactoryInterface.hpp"

class Product : public sf::Drawable, public sf::Transformable
{
    int price;
    std::unique_ptr<Tower> tower;
    TowerType type;

    sf::RectangleShape background;
    sf::Sprite attackIcon;
    sf::Text attackText;
    sf::Sprite coinIcon;
    sf::Text coinText;
public:
    Product(ITowerFactory* _towerFactory, int _price, sf::Vector2f position);

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect(getPosition(), background.getSize());}

    int getPrice() const {return price;}

    TowerType getType() const {return type;}

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        target.draw(background,states);
        target.draw(*tower,states);
        target.draw(attackIcon, states);
        target.draw(attackText, states);
        target.draw(coinIcon, states);
        target.draw(coinText, states);
    }
};
