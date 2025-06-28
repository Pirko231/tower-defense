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

    TowerTexture archerTower;
private:
    AssetLoader()
    {
        archerTower.tower.loadFromFile("resources/textures/tower.png");
        archerTower.archer.loadFromFile("resources/textures/archer.png");
    }
};

} // util
