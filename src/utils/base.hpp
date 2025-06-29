#pragma once
#include "assetloader.hpp"
#include "pressed.hpp"

namespace util
{
    // @brief rozmiar jednej kratki w pikselach. Domyslnie na ekranie miesci sie 20x13
    constexpr sf::Vector2i tileSize = sf::Vector2i(64, 64);
    constexpr sf::Vector2i mapSize = sf::Vector2i(20,13);

    constexpr inline sf::Vector2f calculatePosition(sf::Vector2i mapPos)
    {
        sf::Vector2f newPos;
        newPos.x = static_cast<float>(mapPos.x) * tileSize.x;
        newPos.y = static_cast<float>(mapPos.y) * tileSize.y;

        return newPos;
    }

    constexpr inline sf::Vector2i calculatePosition(sf::Vector2f mapPos)
    {
        sf::Vector2i newPos;
        newPos.x = static_cast<int>(mapPos.x) / tileSize.x;
        newPos.y = static_cast<int>(mapPos.y) / tileSize.y;
        return newPos;
    }

    constexpr inline int calculateIndex(sf::Vector2i mapPos)
    {
        int result{};

        result += mapSize.x * mapPos.y;
        result += mapPos.x;
        return result;
    }
};