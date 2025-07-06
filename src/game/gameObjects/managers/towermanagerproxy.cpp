//
// Created by szymek on 30.06.25.
//

#include "towermanagerproxy.hpp"

bool TowerManagerProxy::addTower(sf::Vector2i where, ITowerFactory* towerFactory)
{
    Map* map = towerManager->map;
    auto buildPoint = map->getBuildPoint(where);
    if (!buildPoint)
        return false;
    if (buildPoint->getTower())
        return false;

    towerManager->addTower(where, towerFactory);
    return true;
}
