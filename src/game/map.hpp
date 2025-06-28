#pragma once
#include <fstream>
#include <filesystem>
#include "assetloader.hpp"

class Tile : public sf::Drawable, public sf::Transformable
{
    sf::Sprite sprite;
public:
    Tile(const sf::Texture& texture)
        : sprite(texture)
    {}

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        target.draw(sprite,states);
    }
};

enum class TileType
{
    Empty = 0,
    Grass = 1
};

/// @brief wczytuje mape z pliku i przechowuje ja
class Map
{
    std::vector<Tile> tiles;
public:
    Map();

    void display(sf::RenderWindow* window)
    {
        for (auto& tile : tiles)
            window->draw(tile);
    }

private:
    /// @brief laduje mape z pliku i zapisuje ja do pojemnika
    void loadMap(const std::filesystem::path& path);

    /// @brief zwraca odpowiedni tile do podanego typu. Kiedy typ sie nie zgadza zwraca Tile bez tekstury
    Tile createTile(TileType type);
};
