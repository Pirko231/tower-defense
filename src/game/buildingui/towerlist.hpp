#pragma once
#include "product.hpp"
#include "../map.hpp"
#include "../gameObjects/factories/archerFactory.hpp"

class TowerList : public sf::Drawable
{
    Map* map{};

    bool visible{};
    sf::RectangleShape background;

    std::vector<Product> products;
public:
    TowerList(Map* _map);

    void setVisible(sf::Vector2i mousePos, bool visible);

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
