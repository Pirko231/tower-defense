#pragma once
#include  "turretInterface.hpp"
#include "clientEnemyManagerInterface.hpp"
#include <memory>

enum class TowerType
{
    SingleCannon = 1
};

class Tower : public sf::Drawable, public sf::Transformable
{
    IClientEnemyManager* enemyManager{};

    sf::Sprite sprite;
    std::unique_ptr<ITurret> turret;

    TowerType type;
public:
    Tower(IClientEnemyManager* _enemyManager, const sf::Texture& towerTexture, std::unique_ptr<ITurret>&& _turret, TowerType _type);
    ~Tower() override = default;

    Tower(Tower& tower)
        : enemyManager(tower.enemyManager), sprite(tower.sprite), turret(std::move(tower.turret)),
        type(tower.type)
    {}

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect(getPosition(), sprite.getGlobalBounds().size);}

    TowerType getType() const {return type;}

    void update();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        target.draw(sprite, states);

        target.draw(*turret, states);
    }
};
