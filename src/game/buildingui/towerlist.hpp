#pragma once
#include "product.hpp"
#include "../map.hpp"
#include "../gameObjects/factories/singleCannonFactory.hpp"
#include "managers/towermanagerproxy.hpp"

class TowerList : public sf::Drawable
{
    Map* map{};
    const int* money{};
    const int* health{};

    bool visible{};
    sf::RectangleShape background;

    sf::Sprite moneyIcon;
    sf::Text moneyText;

    sf::Sprite healthIcon;
    sf::Text healthText;

    std::vector<Product> products;
public:
    TowerList(Map* _map, const int* money, const int* health);

    void setVisible(sf::Vector2i mousePos, bool visible);

    bool isVisible() const {return visible;}

    /// @return jezeli kliknieto w jakis produkt to zwraca produkt
    const Product* click(sf::Vector2i mousePos);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        if (visible)
        {
            // trzeba zmodyfikowac liczbe pieniedzy co klatke
            const_cast<sf::Text*>(&moneyText)->setString(std::to_string(*money));
            const_cast<sf::Text*>(&healthText)->setString(std::to_string(*health));

            target.draw(background, states);
            target.draw(moneyIcon, states);
            target.draw(moneyText, states);
            target.draw(healthIcon, states);
            target.draw(healthText, states);
            for (auto& i : products)
                target.draw(i,states);
        }
    }
};
