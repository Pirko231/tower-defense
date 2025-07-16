#pragma once
#include  "archerInterface.hpp"
#include "clientEnemyManagerInterface.hpp"
#include <memory>

enum class TowerType
{
    Archer = 0
};

class Tower : public sf::Drawable, public sf::Transformable
{
    IClientEnemyManager* enemyManager{};

    sf::Sprite sprite;
    std::unique_ptr<IArcher> archer;

    TowerType type;
public:
    Tower(IClientEnemyManager* _enemyManager, const sf::Texture& towerTexture, std::unique_ptr<IArcher>&& _archer, TowerType _type);
    ~Tower() override = default;

    Tower(Tower& tower)
        : enemyManager(tower.enemyManager), sprite(tower.sprite), archer(std::move(tower.archer)),
        type(tower.type)
    {}

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect(getPosition(), sprite.getGlobalBounds().size);}

    TowerType getType() const {return type;}

    void update();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        target.draw(sprite, states);

        target.draw(*archer, states);
    }
};
