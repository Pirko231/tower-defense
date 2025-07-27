#pragma once
#include "../bullets/basicBullet.hpp"
#include "../enemies/enemy.hpp"
#include "bulletManagerInterface.hpp"
#include "../levels.hpp"

class Turret : public sf::Drawable, public sf::Transformable
{
private:
    sf::Sprite sprite;
    Levels upgrades;
protected:
    IBulletManager* bulletManager{};

    
    int maxCooldown{100};
    int cooldown{};
public:
    virtual void update();

    /// @brief oblicza i zwraca obrazenia na klatke
    virtual float getDPS() const {return (float)upgrades.getCurrentStats().damage / (float)maxCooldown;}

    float getRange() const {return upgrades.getCurrentStats().range;}

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect{getPosition(), sprite.getGlobalBounds().size};}

    virtual void shoot(sf::Vector2f from, Enemy* target) = 0;

    int getUpgradePrice() const {return upgrades.getNextStats().price;}

    int getLevel() const {return upgrades.getCurrentLevel();}

    int getMaxLevel() const {return upgrades.getMaxLevel();}

    /// @brief mnozy statyskyki o doubler
    void upgrade()
    {
        if(upgrades.getCurrentLevel() < upgrades.getMaxLevel())
            upgrades.nextLevel();
    }
protected:
    explicit Turret(const sf::Texture& _texture, IBulletManager* _bulletManager, const std::filesystem::path& upgradesPath)
        : sprite(_texture), upgrades{upgradesPath}, bulletManager(_bulletManager),  cooldown{maxCooldown}
    {}

    void setRange(float _range) {;/*upgrades.getCurrentStats().range = _range;*/}

    Stats getStats() const {return upgrades.getCurrentStats();}

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        target.draw(sprite, states);
    }
};