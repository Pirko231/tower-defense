//
// Created by szymek on 01.07.25.
//

#include "mapbutton.hpp"

namespace btn
{
    MapButton::MapButton(const sf::Font &font, const std::filesystem::path& _mapName)
        : text(font), mapPath(_mapName)
    {
        background.setFillColor(sf::Color::Green);

        background.setSize({220.f,240.f});
    }

    void MapButton::update()
    {
    }

    bool MapButton::isPressed(sf::Vector2i mousePos) const
    {
        if (getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
            return true;
        return false;
    }
} // btn