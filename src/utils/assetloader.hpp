#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#pragma GCC diagnostic ignored "-Wunused-result"

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
    sf::Texture mapButton;

    sf::Texture attackIcon;
    sf::Texture coinIcon;
    sf::Texture rangeIcon;
    sf::Texture healthIcon;
    sf::Texture binIcon;

    sf::Texture towerBase;
    sf::Texture singleCannon;
    sf::Texture doubleCannon;
    sf::Texture machineGun;
    sf::Texture rocketLauncher;

    sf::Texture basicSoldier;
    sf::Texture eliteSoldier;
    sf::Texture mechaSoldier;
    sf::Texture superSoldier;

    sf::Texture basicBullet;
    sf::Texture rocket;

    sf::Texture grassTile;
    sf::Texture dirtTile;
    sf::Texture sandTile;
    sf::Texture pinkGrassTile;
    sf::Texture iceTile;
    sf::Texture hellTile;
    sf::Texture roadTile;
    sf::Texture buildPoint;

    sf::Texture springTree;
    sf::Texture summerTree;
    sf::Texture summerBush;
    sf::Texture winterTree;
    sf::Texture winterTrunk;
    sf::Texture cactus1;
    sf::Texture cactus2;
    sf::Texture moldTree1;
    sf::Texture moldTree2;
    sf::Texture hellTree;
    sf::Texture hellTrunk;
private:
    AssetLoader()
    {
        font.openFromFile("resources/fonts/arial.ttf");

        attackIcon.loadFromFile("resources/textures/attackIcon.png");
        coinIcon.loadFromFile("resources/textures/coinIcon.png");
        rangeIcon.loadFromFile("resources/textures/rangeIcon.png");
        healthIcon.loadFromFile("resources/textures/healthIcon.png");
        binIcon.loadFromFile("resources/textures/binIcon.png");

        background.loadFromFile("resources/textures/background.jpg");
        playButton.loadFromFile("resources/textures/Play.png");
        mapButton.loadFromFile("resources/textures/mapBar.png");

        towerBase.loadFromFile("resources/textures/turrets/towerBase.png");
        singleCannon.loadFromFile("resources/textures/turrets/cannon1.png");
        doubleCannon.loadFromFile("resources/textures/turrets/cannon2.png");
        machineGun.loadFromFile("resources/textures/turrets/MG.png");
        rocketLauncher.loadFromFile("resources/textures/turrets/rocketLauncher.png");

        basicSoldier.loadFromFile("resources/textures/enemies/basicSoldier.png");
        eliteSoldier.loadFromFile("resources/textures/enemies/eliteSoldier.png");
        mechaSoldier.loadFromFile("resources/textures/enemies/mechaSoldier.png");
        superSoldier.loadFromFile("resources/textures/enemies/superSoldier.png");

        basicBullet.loadFromFile("resources/textures/bullets/basicBullet.png");
        rocket.loadFromFile("resources/textures/bullets/rocket.png");

        grassTile.loadFromFile("resources/textures/tiles/grass.png");
        dirtTile.loadFromFile("resources/textures/tiles/dirt.png");
        sandTile.loadFromFile("resources/textures/tiles/sand.png");
        pinkGrassTile.loadFromFile("resources/textures/tiles/pinkGrass.png");
        iceTile.loadFromFile("resources/textures/tiles/ice.png");
        hellTile.loadFromFile("resources/textures/tiles/hellGrass.png");
        roadTile.loadFromFile("resources/textures/tiles/road.png");
        buildPoint.loadFromFile("resources/textures/tiles/build.png");

        springTree.loadFromFile("resources/textures/decorations/springTree.png");
        summerTree.loadFromFile("resources/textures/decorations/summerTree.png");
        summerBush.loadFromFile("resources/textures/decorations/summerBerryBush.png");
        winterTree.loadFromFile("resources/textures/decorations/winterTree.png");
        winterTrunk.loadFromFile("resources/textures/decorations/winterTrunk.png");
        cactus1.loadFromFile("resources/textures/decorations/cactus1.png");
        cactus2.loadFromFile("resources/textures/decorations/cactus2.png");
        moldTree1.loadFromFile("resources/textures/decorations/moldTree1.png");
        moldTree2.loadFromFile("resources/textures/decorations/moldTree2.png");
        hellTree.loadFromFile("resources/textures/decorations/hellTree.png");
        hellTrunk.loadFromFile("resources/textures/decorations/hellTrunk.png");
    }
};

} // util
