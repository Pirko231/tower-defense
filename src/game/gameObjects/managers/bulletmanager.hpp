#pragma once
#include "enemymanager.hpp"
#include "../bullets/basicBullet.hpp"
#include "../bullets/rocket.hpp"
#include "bulletManagerInterface.hpp"

class BulletManager : public sf::Drawable, public IBulletManager
{
    EnemyManager* enemyManager{};
    std::vector<std::unique_ptr<Bullet>> bullets;
public:
    BulletManager(EnemyManager* _enemyManager);

    void update();

    void launchBasicBullet(sf::Vector2f from, sf::Vector2f where, Enemy* target, int damage) override;

    void launchRocket(sf::Vector2f from, sf::Vector2f where, Enemy* target, int damage) override;
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        for(auto& bullet : bullets)
            target.draw(*bullet);
    }
};