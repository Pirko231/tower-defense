#include "buildingui.hpp"

BuildingUI::BuildingUI(Map *_map)
    : map(_map), towerList(_map)
{
    mapPointer.setFillColor({20,20,100,80});
    mapPointer.setSize(static_cast<sf::Vector2f>(util::tileSize));
}

void BuildingUI::click(sf::Vector2i where)
{
    auto tile = map->findTile(where);

    mapPointer.setPosition(tile->getPosition());

    towerList.setVisible(where, true);

    mapPointerVisible = true;
}
