#include "bulletmanager.hpp"

BulletManager::BulletManager(EnemyManager* _enemyManager)
    : enemyManager(_enemyManager)
{
}

void BulletManager::update()
{
    for(auto& bullet : bullets)
        bullet->update();
}

void BulletManager::launchBasicBullet(sf::Vector2f from, sf::Vector2f where, Enemy *target, int damage)
{
    BasicBullet bullet{target, damage};
    bullet.launch(from, where);
    bullets.push_back(std::make_unique<BasicBullet>(bullet));
}

void BulletManager::launchRocket(sf::Vector2f from, sf::Vector2f where, Enemy *target, int damage)
{

    Rocket rocket{target, damage};
    rocket.launch(from, where);
    bullets.push_back(std::make_unique<Rocket>(rocket));
}
