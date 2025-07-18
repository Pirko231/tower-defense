#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#pragma GCC diagnostic ignored "-Wunused-result"

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

    sf::Texture background;
    sf::Texture playButton;

    sf::Texture attackIcon;
    sf::Texture coinIcon;
    sf::Texture healthIcon;

    sf::Texture towerBase;
    sf::Texture cannon1;

    sf::Texture basicSoldier;

    sf::Texture basicBullet;

    sf::Texture grassTile;
    sf::Texture dirtTile;
    sf::Texture sandTile;
    sf::Texture roadTile;
    sf::Texture buildPoint;
private:
    AssetLoader()
    {
        font.openFromFile("resources/fonts/arial.ttf");

        attackIcon.loadFromFile("resources/textures/attackIcon.png");
        coinIcon.loadFromFile("resources/textures/coinIcon.png");
        healthIcon.loadFromFile("resources/textures/healthIcon.png");

        background.loadFromFile("resources/textures/background.jpg");
        playButton.loadFromFile("resources/textures/Play.png");

        towerBase.loadFromFile("resources/textures/turrets/towerBase.png");
        cannon1.loadFromFile("resources/textures/turrets/cannon1.png");

        basicSoldier.loadFromFile("resources/textures/enemies/basicSoldier.png");

        basicBullet.loadFromFile("resources/textures/bullets/basicBullet.png");

        grassTile.loadFromFile("resources/textures/tiles/grass.png");
        dirtTile.loadFromFile("resources/textures/tiles/dirt.png");
        sandTile.loadFromFile("resources/textures/tiles/sand.png");
        roadTile.loadFromFile("resources/textures/tiles/road.png");
        buildPoint.loadFromFile("resources/textures/tiles/build.png");
    }
};

} // util
