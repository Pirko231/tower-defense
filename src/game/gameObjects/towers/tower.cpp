#include  "tower.hpp"

Tower::Tower(IClientEnemyManager *_enemyManager, const sf::Texture &towerTexture, std::unique_ptr<IArcher> &&_archer, TowerType _type)
    : enemyManager(_enemyManager), sprite(towerTexture), archer(std::move(_archer)), type(_type)
{
    archer->setOrigin(archer->getGlobalBounds().getCenter());
    archer->setPosition(getGlobalBounds().getCenter());
}

void Tower::update()
{
    // na poczatku trzbea sprawdzic czy enemyManager jest nullptr!!!
    if(!enemyManager)
        return;

    // przeciwnik w ktorego bedziemy strzelac
    auto enemy = enemyManager->getTheMostFarEnemy(archer->getRange());
    if(!enemy)
        return; // brak celow

    // ustawienie rotacji wiezy
    sf::Vector2f offset {getPosition() - enemy->getGlobalBounds().getCenter()};
    offset = offset.normalized();
    archer->setRotation(offset.angle());
}
