//
// Created by szymek on 07.07.25.
//

#include "enemymanager.hpp"

EnemyManager::EnemyManager(Map* _map)
    : map(_map)
{
}

void EnemyManager::update()
{

}

void EnemyManager::loadCheckPoints()
{
    checkpoints.clear();

    auto& tiles = map->getTiles();

    Direction currentDirection;
    auto it = tiles.begin();

    for (auto it = tiles.begin() + 1; it != tiles.end(); it++)
        if (currentDirection != checkDirection(*it, *(it + 1)))
        {
            currentDirection = checkDirection(*it, *(it + 1));
            checkpoints.push_back(it->getPosition());
        }
}

void EnemyManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& i : checkpoints)
        target.draw(i, states);
}

EnemyManager::Direction EnemyManager::checkDirection(const Tile& first, const Tile& second)
{
    Direction currentDirection;
    if (first.getPosition().x < second.getPosition().x)
        currentDirection.right = true;
    else
        currentDirection.left = true;
    if (first.getPosition().y < second.getPosition().y)
        currentDirection.down = true;
    else
        currentDirection.up = true;
    return currentDirection;
}
