#pragma once
#include "../../map.hpp"
#include "enemyfactoryinterface.hpp"
#include "../factories/basicSoldierFactory.hpp"

class EnemyManager : public sf::Drawable
{
    Map* map{};
    int* baseHealth{};

    std::vector<std::unique_ptr<Enemy>> enemies;
public:
    EnemyManager(Map* _map, int* _health);

    void update();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

