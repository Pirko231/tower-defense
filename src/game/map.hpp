#pragma once
#include <fstream>
#include <filesystem>
#include "assetloader.hpp"

enum class TileType
{
    Empty = 0,
    Grass = 1,
    Dirt = 2,
    Sand = 3,
    Road = 4,
    BuildPoint = 5
};

class Tile : public sf::Drawable, public sf::Transformable
{
    sf::Sprite sprite;
    TileType type;
public:
    Tile(const sf::Texture& texture, TileType type)
        : sprite(texture), type(type)
    {}

    TileType getType() const {return type;}

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        target.draw(sprite,states);
    }
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
