#include "towermanager.hpp"

#include "base.hpp"

void TowerManager::addTower(sf::Vector2i where, TowerType type)
{
    if (type == TowerType::Archer)
    {
        ArcherFactory archerFactory;
        auto tower = archerFactory.create();
        tower->setPosition(util::calculatePosition(where));
        towers.push_back(std::move(tower));
    }
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
