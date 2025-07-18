#include  "tower.hpp"

Tower::Tower(IClientEnemyManager *_enemyManager, const sf::Texture &towerTexture, std::unique_ptr<ITurret> &&_turret, TowerType _type)
    : enemyManager(_enemyManager), sprite(towerTexture), turret(std::move(_turret)), type(_type)
{
    turret->setOrigin(turret->getGlobalBounds().getCenter());
    turret->setPosition(getGlobalBounds().getCenter());
}

void Tower::update()
{
    // na poczatku trzbea sprawdzic czy enemyManager jest nullptr!!!
    if(!enemyManager)
        return;

    turret->update(); // szybki update pociskow

    // zasieg wiezy
    sf::FloatRect range{{0.f,0.f}, {turret->getRange(),turret->getRange()}};
    range.position = getGlobalBounds().getCenter() - range.size / 2.f;

    // przeciwnik w ktorego bedziemy strzelac
    auto enemy = enemyManager->getTheMostFarEnemy(range);
    if(!enemy)
        return; // brak celow

    // ustawienie rotacji wiezy
    sf::Vector2f offset {getPosition() - enemy->getGlobalBounds().getCenter()};
    offset = offset.normalized();
    turret->setRotation(offset.angle());

    turret->shoot(getGlobalBounds().getCenter(),enemy);
}
