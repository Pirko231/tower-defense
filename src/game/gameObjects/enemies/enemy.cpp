#include "enemy.hpp"

Enemy::Enemy(const sf::Texture& _texture, Checkpoint::Iterator _checkpoint, int _moneyValue, int _maxHealth, int _damage, int _shield, float _speed)
    : maxHealth(_maxHealth), speed(_speed), damage(_damage), shield(_shield), moneyValue(_moneyValue), sprite(_texture), currentCheckpoint(_checkpoint)
{
    setOrigin(getGlobalBounds().getCenter());;

    sf::Vector2f mBy = getPosition() - calculateCheckpointsHitbox().position;
    if(mBy != sf::Vector2f{})
        moveBy = mBy.normalized();

    setRotation(moveBy.angle());
}

void Enemy::update()
{
    move(moveBy);

    arrivalTimer--;
    if(hasReachedDestination())
        nextDestination();

    healthBar.setPosition({getPosition().x - healthBar.getGlobalBounds().size.x / 2.f, getPosition().y - getGlobalBounds().size.y / 1.5f});
    healthBar.update(health);
}

void Enemy::calculateMoveBy()
{
    sf::Vector2f mBy = calculateCheckpointsHitbox().position - getPosition();
    if(mBy != sf::Vector2f{})
    {
        arrivalTimer = mBy.length() / speed;
        moveBy = mBy.normalized() * speed;
        setRotation(moveBy.angle());
    }
    else
        arrivalTimer = 0;
}

bool Enemy::hasReachedDestination() const
{
    return arrivalTimer <= 0;
}

void Enemy::nextDestination()
{
    if(!currentCheckpoint.hasNext())
        return;
    currentCheckpoint++;

    calculateMoveBy();
}

sf::FloatRect Enemy::calculateCheckpointsHitbox() const
{
    auto center = currentCheckpoint->getGlobalBounds().getCenter();
    sf::FloatRect rect{center, currentCheckpoint->getGlobalBounds().size / 10.f};
    rect.position -= rect.size / 2.f;

    return rect;
}
