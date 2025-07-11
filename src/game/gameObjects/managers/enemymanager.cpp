#include "enemymanager.hpp"

EnemyManager::EnemyManager(Map* _map, int* _health)
    : map(_map), baseHealth(_health)
{
    // utworzenie jakiegokolwiek przeciwinika w tym momencie powoduje segfault
    // poniewaz checkpointy sa puste podczas inicjalizacji
}

void EnemyManager::update()
{
    for(auto it = enemies.begin(); it != enemies.end(); it++)
    {
        std::unique_ptr<Enemy>& enemy = *it;
        enemy->update();
        if (!enemy->hasNext())
        {
            *baseHealth -= enemy->getDamage();
            enemies.erase(it);
            it--;
        }
    }

    

    // wywalic kiedy bedzie powazniejszy mechanizm do dodawania przeciwnikow
    static bool v{};
    if(!v)
    {
        BasicSoldierFactory f;
        auto e = f.create(map->getCheckpointIterator());
        e->setPosition(map->getEntrance()->getPosition());
        e->calculateMoveBy();
        enemies.push_back(std::move(e));
    }
    v = true;
}

void EnemyManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& enemy : enemies)
        target.draw(*enemy,states);
}
