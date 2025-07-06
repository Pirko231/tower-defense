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

        // zalozenie ze jest wartosc - sprawdzone wczesniej w proxy
        map->getBuildPoint(where)->setTower(towers.back().get());
    }
    else
        std::cerr << "TowerManager::addTower: TowerType not implemented" << std::endl;
}

void TowerManager::update()
{
    for (auto& i : towers)
        i->update();
}

void TowerManager::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto& i : towers)
        target.draw(*i,states);
}
