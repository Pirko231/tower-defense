#pragma once
#include <fstream>
#include <filesystem>
#include "assetloader.hpp"
#include "base.hpp"
#include "towers/tower.hpp"

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

class BuildPoint : public sf::Drawable, public sf::Transformable
{
    sf::Sprite sprite;
    Tower* tower{};
public:
    explicit BuildPoint(const sf::Texture& texture)
        : sprite(texture)
    {}

    void setTower(Tower* _tower) {tower = _tower;}

    Tower* getTower() const {return tower;}

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        if (!tower)
            target.draw(sprite,states);
    }
};

/// @brief wczytuje mape z pliku i przechowuje ja
class Map
{
    std::vector<Tile> tiles;
    std::vector<BuildPoint> buildPoints;
public:
    Map();

    void display(sf::RenderWindow* window)
    {
        for (auto& tile : tiles)
            window->draw(tile);
        for (auto& buildPoint : buildPoints)
            window->draw(buildPoint);
    }

    BuildPoint* getBuildPoint(sf::Vector2i pos)
    {
        auto result = std::find_if(buildPoints.begin(), buildPoints.end(),
            [&pos](const BuildPoint& bp)->bool{return util::calculatePosition(bp.getPosition()) == pos;});
        if (result != buildPoints.end())
            return &(*result);
        return nullptr;
    }

    Tile* findTile(sf::Vector2i mousePos)
    {
        // z zaokraglenia do liczby calkowitej wyjdzie ilosc pol
        mousePos.x /= util::tileSize.x;
        mousePos.y /= util::tileSize.y;

        return &tiles[(mousePos.y * util::mapSize.x) + mousePos.x];
    }

private:
    /// @brief laduje mape z pliku i zapisuje ja do pojemnika
    void loadMap(const std::filesystem::path& path);

    /// @brief zwraca odpowiedni tile do podanego typu. Kiedy typ sie nie zgadza zwraca Tile bez tekstury
    Tile createTile(TileType type);
};
