#pragma once
#include "product.hpp"
#include "../map.hpp"
#include "../gameObjects/factories/archerFactory.hpp"
#include "managers/towermanagerproxy.hpp"

class TowerList : public sf::Drawable
{
    Map* map{};

    bool visible{};
    sf::RectangleShape background;

    std::vector<Product> products;
public:
    TowerList(Map* _map);

    void setVisible(sf::Vector2i mousePos, bool visible);

    bool isVisible() const {return visible;}

    /// @return jezeli kliknieto w jakis produkt to zwraca produkt
    std::optional<const Product*> click(sf::Vector2i mousePos);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        if (visible)
        {
            target.draw(background, states);
            for (auto& i : products)
                target.draw(i,states);
        }
    }
};
