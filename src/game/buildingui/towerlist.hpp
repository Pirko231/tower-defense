#pragma once
#include "product.hpp"
#include "../map.hpp"
#include "../gameObjects/factories/archerFactory.hpp"
#include "managers/towermanagerproxy.hpp"

class TowerList : public sf::Drawable
{
    Map* map{};
    const int* money{};

    bool visible{};
    sf::RectangleShape background;

    sf::Sprite moneyIcon;
    sf::Text moneyText;

    std::vector<Product> products;
public:
    TowerList(Map* _map, const int* money);

    void setVisible(sf::Vector2i mousePos, bool visible);

    bool isVisible() const {return visible;}

    /// @return jezeli kliknieto w jakis produkt to zwraca produkt
    std::optional<const Product*> click(sf::Vector2i mousePos);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        if (visible)
        {
            // trzeba zmodyfikowac liczbe pieniedzy co klatke
            const_cast<sf::Text*>(&moneyText)->setString(std::to_string(*money));

            target.draw(background, states);
            target.draw(moneyIcon, states);
            target.draw(moneyText, states);
            for (auto& i : products)
                target.draw(i,states);
        }
    }
};
