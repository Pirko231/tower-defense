#include "bulletmanager.hpp"

BulletManager::BulletManager(EnemyManager* _enemyManager)
    : enemyManager(_enemyManager)
{
}

void BulletManager::update()
{
    std::erase_if(rockets, [this](auto& rocket)
    {

        if(!enemyManager->findAdress(rocket->getTarget()))
        {
            if(!enemyManager->empty())
            {
                rocket->setTarget(enemyManager->getTheMostFarEnemy(sf::FloatRect{{0.f,0.f}, {util::mapSize.x * util::tileSize.x, util::mapSize.y * util::tileSize.y}}));
            }
            else
            {
                rocket->setDelete(true);
                return true;
            }
        }
        return false;
    });
    // specjalny case dla rakiet
        

    for(auto& bullet : bullets)
    {
        bullet->update();
        if(bullet->hasHitTarget())
        {
            if(enemyManager->findAdress(bullet->getTarget()))
            {
                bullet->hitTarget();
                // kasowanie rakiet
                if(dynamic_cast<Rocket*>(bullet.get()))
                {
                    Rocket* r = static_cast<Rocket*>(bullet.get());
                    std::erase_if(rockets, [r](const auto& rocket){return rocket == r;});
                }
            }
            else
                bullet->setDelete(true);
        }
    }

    std::erase_if(bullets, [](const std::unique_ptr<Bullet>& b)->bool{return b->shouldDelete();});
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

    rockets.push_back(static_cast<Rocket*>(bullets.back().get()));
}
