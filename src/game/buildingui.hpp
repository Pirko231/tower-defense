#pragma once
#include <SFML/Graphics.hpp>
#include "map.hpp"

class BuildingUI : public sf::Drawable
{
    Map* map{};

    sf::RectangleShape mapPointer;
    bool mapPointerVisible{};
    sf::RectangleShape background;
public:
    BuildingUI(Map* _map);

    /// @brief przyjmuje pozycje myszy i ustawia kwadrat do klikneicia
    void click(sf::Vector2i where);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        if (mapPointerVisible)
        {
            target.draw(mapPointer, states);
            target.draw(background, states);
        }
    }
};
