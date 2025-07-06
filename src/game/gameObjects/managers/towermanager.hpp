#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "towerFactoryInterface.hpp"
#include "factories/archerFactory.hpp"
#include "../map.hpp"


class TowerManager : public sf::Drawable
{
    friend class TowerManagerProxy;

    std::vector<std::unique_ptr<Tower>> towers;
    Map* map{};
public:
    explicit TowerManager(Map* _map) : map(_map)
    {}

    void update();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
private:
    void addTower(sf::Vector2i where, ITowerFactory* towerFactory);
};
