//
// Created by szymek on 30.06.25.
//

#include "towermanagerproxy.hpp"

void TowerManagerProxy::addTower(sf::Vector2i where, ITowerFactory* towerFactory)
{
    Map* map = towerManager->map;
    auto buildPoint = map->getBuildPoint(where);
    if (!buildPoint)
        return;
    if (buildPoint->getTower())
        return;

    towerManager->addTower(where, towerFactory);
}
