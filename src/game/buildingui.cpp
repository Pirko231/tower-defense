#include "buildingui.hpp"

BuildingUI::BuildingUI(Map *_map)
    : map(_map)
{
    mapPointer.setFillColor({20,20,100,80});
    mapPointer.setSize(static_cast<sf::Vector2f>(util::tileSize));

    sf::Vector2f size = {util::mapSize.x * util::tileSize.x, util::mapSize.y * util::tileSize.y};
    background.setSize({size.x / 2.f, size.y});
    background.setFillColor({255,255,255,120});
}

void BuildingUI::click(sf::Vector2i where)
{
    auto tile = map->findTile(where);

    mapPointer.setPosition(tile->getPosition());

    sf::Vector2f size = {util::mapSize.x * util::tileSize.x, util::mapSize.y * util::tileSize.y};
    if (tile->getPosition().x >= size.x / 2.f)
        background.setPosition({0.f,0.f});
    else
        background.setPosition({size.x / 2.f,0.f});

    mapPointerVisible = true;
}
