#pragma once
#include "../../map.hpp"
#include "enemyfactoryinterface.hpp"
#include "clientEnemyManagerInterface.hpp"

class EnemyManager : public sf::Drawable, public IClientEnemyManager
{
    Map* map{};
    int* baseHealth{};
    int* money{};

    std::vector<std::unique_ptr<Enemy>> enemies;
public:
    EnemyManager(Map* _map, int* _health, int* _money);

    void update();

    Enemy* getTheMostFarEnemy(sf::FloatRect area) override;

    void addEnemy(IEnemyFactory* factory)
    {
        enemies.push_back(std::move(factory->create(map->getCheckpointIterator())));
        enemies.back()->setPosition(map->getEntrance()->getGlobalBounds().getCenter());
        enemies.back()->calculateMoveBy();
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

