#include "mapbutton.hpp"
#include "assetloader.hpp"

namespace btn
{
    MapButton::MapButton(const sf::String& _mapName, const std::filesystem::path& _mapPath, const std::filesystem::path& _enemyPath, int _decorationAmount)
        : text(util::AssetLoader::get().font), background(util::AssetLoader::get().mapButton), mapPath(_mapPath), decorationAmount(_decorationAmount)
    {
        mapPath = "resources/data/maps/";
        mapPath += _mapPath;

        enemyPath = "resources/data/maps/";
        enemyPath += _enemyPath;

        background.setScale({4.f,18.f});

        text.setString(_mapName);
        text.setCharacterSize(40.f);
        text.setPosition({getGlobalBounds().getCenter().x - text.getGlobalBounds().size.x / 2.f, getGlobalBounds().getCenter().y - text.getGlobalBounds().size.y / 1.f});
    }

    MapButton::MapButton(MapInfo::MapData data)
        : MapButton(data.name, data.mapPath, data.enemyPath, data.decorAmount)
    {}

    void MapButton::update()
    {
    }

    bool MapButton::isPressed(sf::Vector2i mousePos) const
    {
        if (getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
            return true;
        return false;
    }
} // btn