#include "towermanager.hpp"

#include "base.hpp"

void TowerManager::addTower(sf::Vector2i where, ITowerFactory* towerFactory)
{
    auto tower = towerFactory->create(static_cast<IClientEnemyManager*>(enemyManager), bulletManager);
    tower->setPosition(util::calculatePosition(where));
    towers.push_back(std::move(tower));

    // zalozenie ze jest wartosc - sprawdzone wczesniej w proxy
    map->getBuildPoint(where)->setTower(towers.back().get());
}

void TowerManager::update()
{
    for (auto& i : towers)
        i->update();
}

int TowerManager::destructTowers(sf::Vector2f mapPointerPos)
{
    int moneyValue{};
    std::erase_if(towers, [&moneyValue, mapPointerPos, this](const auto& tower)
    {
        if(tower->getPosition() == mapPointerPos)
        {
            if(auto bp = map->getBuildPoint(util::calculatePosition(mapPointerPos)))
                bp->setTower(nullptr);
            moneyValue = tower->getPrice();
            return true;
        }
        return false;
    });
    return moneyValue;
}

void TowerManager::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto& i : towers)
        target.draw(*i,states);
}
