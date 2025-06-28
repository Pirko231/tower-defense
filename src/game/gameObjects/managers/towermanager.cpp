#include "towermanager.hpp"

void TowerManager::addTower(sf::Vector2i where, TowerType what)
{
    ArcherFactory archerFactory;
    towers.push_back(std::move(archerFactory.create()));
}

void TowerManager::update()
{
    for (auto& i : towers)
        i->update();
}

void TowerManager::display(sf::RenderWindow *window)
{
    for (auto& i : towers)
        window->draw(*i);
}
