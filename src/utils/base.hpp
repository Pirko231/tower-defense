#pragma once
#include "assetloader.hpp"
#include "pressed.hpp"

namespace util
{
    // @brief rozmiar jednej kratki w pikselach. Domyslnie na ekranie miesci sie 20x13
    constexpr sf::Vector2i tileSize = sf::Vector2i(64, 64);

    inline sf::Vector2f calculatePosition(sf::Vector2i mapPos)
    {
        sf::Vector2f newPos;
        newPos.x = static_cast<float>(mapPos.x) * tileSize.x;
        newPos.y = static_cast<float>(mapPos.y) * tileSize.y;

        return newPos;
    }

    inline sf::Vector2i calculatePosition(sf::Vector2f mapPos)
    {
        sf::Vector2i newPos;
        newPos.x = static_cast<int>(mapPos.x) / tileSize.x;
        newPos.y = static_cast<int>(mapPos.y) / tileSize.y;
        return newPos;
    }


};