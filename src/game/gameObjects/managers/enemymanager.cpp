#include "enemymanager.hpp"

EnemyManager::EnemyManager(Map* _map)
    : map(_map)
{
}

void EnemyManager::update()
{

}

void EnemyManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& enemy : enemies)
        target.draw(*enemy,states);
}
