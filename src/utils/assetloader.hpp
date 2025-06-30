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
    sf::Font font;

    sf::Texture towerBase;
    sf::Texture cannon1;

    sf::Texture grassTile;
    sf::Texture dirtTile;
    sf::Texture sandTile;
    sf::Texture roadTile;
    sf::Texture buildPoint;
private:
    AssetLoader()
    {
        font.openFromFile("resources/fonts/arial.ttf");

        towerBase.loadFromFile("resources/textures/archers/towerBase.png");
        cannon1.loadFromFile("resources/textures/archers/cannon1.png");

        grassTile.loadFromFile("resources/textures/tiles/grass.png");
        dirtTile.loadFromFile("resources/textures/tiles/dirt.png");
        sandTile.loadFromFile("resources/textures/tiles/sand.png");
        roadTile.loadFromFile("resources/textures/tiles/road.png");
        buildPoint.loadFromFile("resources/textures/tiles/build.png");
    }
};

} // util
