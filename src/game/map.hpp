#pragma once
#include <fstream>
#include <filesystem>
#include "assetloader.hpp"
#include "base.hpp"
#include "towers/tower.hpp"
#include "checkpoint.hpp"

enum class TileType
{
    Empty = 0,
    Grass = 10,
    Dirt = 11,
    Sand = 12,
    PinkGrass = 13,
    Ice = 14,
    Road = 30,
    Checkpoint = 31,
    Entrance = 32,
    Exit = 33,
    BuildPoint = 50
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

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect{getPosition(), sprite.getGlobalBounds().size};}

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
class Map : public sf::Drawable
{
    std::vector<Tile> tiles;
    Tile* entrance{};
    Tile* exit{};
    std::vector<BuildPoint> buildPoints;
    std::vector<Checkpoint> checkpoints;

    std::vector<sf::Sprite> decorations;
public:
    Map();

    const std::vector<Tile>& getTiles() const {return tiles;}

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override
    {
        for (auto& tile : tiles)
            target.draw(tile,states);
        for (auto& buildPoint : buildPoints)
            target.draw(buildPoint,states);
        for (auto& checkpoint : checkpoints)
            target.draw(checkpoint,states);
        for(auto& decoration : decorations)
        {
            target.draw(decoration,states);
            sf::RectangleShape shape{{64.f,64.f}};
            shape.setPosition(decoration.getPosition());
            shape.setFillColor(sf::Color{255,255,255,100});
            target.draw(shape);
        }
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

    Checkpoint* getCheckpoint(sf::Vector2i pos)
    {
        auto result = std::find_if(checkpoints.begin(), checkpoints.end(),
            [&pos](const auto& checkpoint)->bool{return util::calculatePosition(checkpoint.getPosition()) == pos;});
        if (result != checkpoints.end())
            return &(*result);
        return nullptr;
    }

    Tile* getEntrance() {return entrance;}

    Tile* getExit() {return exit;}

    Checkpoint::Iterator getCheckpointIterator() {return Checkpoint::Iterator{checkpoints.begin(), checkpoints};}

    /// @brief laduje mape z pliku i zapisuje ja do pojemnika
    void loadMap(const std::filesystem::path& path, int numberOfDecorations);

private:
    /// @brief sortuje checkpointy przygotowujac je do stanu uzywalnosci. Wywolywane w loadMap
    void sortCheckpoints();

    /// @brief zwraca kolejne pole ktore jest trasa przeciwnikow i obok obecnego
    /// @param tile obecnie sprawdzane pola
    /// @param previousTiles poprzednie pola unikajace kopii
    Tile* findNextPath(Tile* tile, std::vector<Tile*>& previousTiles);

    /// @brief zwraca odpowiedni tile do podanego typu. Kiedy typ sie nie zgadza zwraca Tile bez tekstury
    Tile createTile(TileType type);

    /// @brief uzywa mapy i umieszcza na niej dekoracje
    void placeDecorations(int amount);

    /// @brief zwraca zestaw dekoracji w zaleznosci od podanego typu
    /// @param type najczejsciej wystepujacy typ pola
    /// @return zestaw tekstur zawierajacy dekoracje
    std::vector<const sf::Texture*> getDecorationSet(TileType type) const;

    /// @brief znajduje najczesciej wystepujace pole na mapie z wykluczeniem drog, checkopintow wejscia i wyjsia
    /// @return rodzaj tego pola
    TileType determineMainTileType() const;
};
