#include "enemymanager.hpp"

EnemyManager::EnemyManager(Map* _map)
    : map(_map)
{
    BasicSoldierFactory f;
    enemies.push_back(f.create(map->getCheckpointIterator()));
}

void EnemyManager::update()
{
    for(auto& enemy : enemies)
        enemy->update();
}

void EnemyManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& enemy : enemies)
        target.draw(*enemy,states);
}
