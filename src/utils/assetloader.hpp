#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#pragma ignore warning(disable : 4100)

struct TowerTexture
{
    sf::Texture tower;
    sf::Texture archer;
};

namespace util
{

class AssetLoader
{
public:
    static AssetLoader& get()
    {
        static AssetLoader instance;
        return instance;
    }
    sf::Texture emptyTexture;

    TowerTexture archerTower;

    sf::Texture grassTile;
private:
    AssetLoader()
    {
        archerTower.tower.loadFromFile("resources/textures/tower.png");
        archerTower.archer.loadFromFile("resources/textures/archer.png");

        grassTile.loadFromFile("resources/textures/tiles/grass.png");
    }
};

} // util
