#include "enemymanager.hpp"

EnemyManager::EnemyManager(Map* _map)
    : map(_map)
{
    // utworzenie jakiegokolwiek przeciwinika w tym momencie powoduje segfault
    // poniewaz checkpointy sa puste podczas inicjalizacji
}

void EnemyManager::update()
{
    for(auto& enemy : enemies)
        enemy->update();

    // wywalic kiedy bedzie powazniejszy mechanizm do dodawania przeciwnikow
    static bool v{};
    if(!v)
    {
        BasicSoldierFactory f;
        enemies.push_back(f.create(map->getCheckpointIterator()));
    }
    v = true;
}

void EnemyManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& enemy : enemies)
        target.draw(*enemy,states);
}
