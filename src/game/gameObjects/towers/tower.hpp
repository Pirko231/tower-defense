#pragma once
#include  "../turrets/turret.hpp"
#include "clientEnemyManagerInterface.hpp"
#include <memory>

// to jest nieuzywane?
enum class TowerType
{
    SingleCannon = 1,
    DoubleCannon = 2,
    MachineGun = 3,
    RocketLauncher = 4
};

class Tower : public sf::Drawable, public sf::Transformable
{
    IClientEnemyManager* enemyManager{};

    sf::Sprite sprite;
    std::unique_ptr<Turret> turret;

    TowerType type;
    int price;
public:
    Tower(IClientEnemyManager* _enemyManager, const sf::Texture& towerTexture, std::unique_ptr<Turret>&& _turret, TowerType _type, int _price);
    ~Tower() override = default;

    //Tower(Tower&) = default;
    Tower(Tower&&) = default;

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect(getPosition(), sprite.getGlobalBounds().size);}

    float getRange() const {return turret->getRange();}
    
    TowerType getType() const {return type;}

    float getDPS() const {return turret->getDPS();}

    int getPrice() const {return price;}

    void update();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        target.draw(sprite, states);

        target.draw(*turret, states);
    }
};
