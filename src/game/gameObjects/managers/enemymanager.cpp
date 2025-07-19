#include "enemymanager.hpp"

EnemyManager::EnemyManager(Map* _map, int* _health)
    : map(_map), baseHealth(_health)
{
    // utworzenie jakiegokolwiek przeciwinika w tym momencie powoduje segfault
    // poniewaz checkpointy sa puste podczas inicjalizacji
}

void EnemyManager::update()
{
    std::erase_if(enemies, [](const std::unique_ptr<Enemy>& e)->bool{return e->shouldDelete();});
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

}

Enemy* EnemyManager::getTheMostFarEnemy(sf::FloatRect area)
{
    // Algorytm na razie bedzie dzialal troche inaczej.
    // Ciezko bedzie to zrobic aby brac przeciwnika ktory jest pierwszy.
    // Zrobimy tak ze bedzie bral przeciwnika ktory jest pierwszy w wektorze,
    // bedzie to jednak robilo problemy kiedy przeciwnicy beda zmieniac predkosc.
    // Wtedy bedzie trzeba prawdopodobnie uzywac iterator_swap.
    
    for(auto& enemy : enemies)
    {
        if(enemy->getGlobalBounds().findIntersection(area))
            return enemy.get();
    }
    return nullptr;
}

void EnemyManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& enemy : enemies)
        target.draw(*enemy,states);
}
