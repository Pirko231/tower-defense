#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "towerFactoryInterface.hpp"
#include "factories/singleCannonFactory.hpp"
#include "factories/machineGunFactory.hpp"
#include "../managers/enemymanager.hpp"
#include "../map.hpp"
#include "bulletmanager.hpp"


class TowerManager : public sf::Drawable
{
    friend class TowerManagerProxy;

    std::vector<std::unique_ptr<Tower>> towers;
    Map* map{};
    EnemyManager* enemyManager{};
    BulletManager* bulletManager{};
public:
    explicit TowerManager(Map* _map, EnemyManager* _enemyManager, BulletManager* _bulletManager)
        : map(_map), enemyManager(_enemyManager), bulletManager(_bulletManager)
    {}

    void update();

    /// @brief usuwa wieze i zwraca jej cene
    /// @param mapPointerPos pozycja wiezy
    /// @return cena wiezy
    int destructTowers(sf::Vector2f mapPointerPos);

    void reset() {towers.clear();}
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addTower(sf::Vector2i where, ITowerFactory* towerFactory);
};
