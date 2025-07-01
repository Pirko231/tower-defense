#pragma once
#include "product.hpp"
#include "../map.hpp"

class TowerList : public sf::Drawable
{
    Map* map{};

    bool visible{};
    sf::RectangleShape background;
public:
    TowerList(Map* _map);

    void setVisible(sf::Vector2i mousePos, bool visible);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        if (visible)
            target.draw(background,states);
    }
};
