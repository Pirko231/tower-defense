#include "enemy.hpp"

Enemy::Enemy(const sf::Texture& _texture, Checkpoint::Iterator _checkpoint)
    : sprite(_texture), currentCheckpoint(_checkpoint)
{
    setOrigin(getGlobalBounds().getCenter());

    /*moveBy =  currentCheckpoint->getGlobalBounds().getCenter() - getPosition();
    if(moveBy != sf::Vector2f{})
        moveBy = moveBy.normalized();
    setRotation(moveBy.angle());*/
}

void Enemy::update()
{
    move(moveBy);

    if(hasReachedDestination())
        nextDestination();
}

bool Enemy::hasReachedDestination()
{
    
    return (bool)getGlobalBounds().findIntersection(calculateCheckpointsHitbox());
}

void Enemy::nextDestination()
{
    if(!currentCheckpoint.hasNext())
        return;
    currentCheckpoint++;

    sf::Vector2f mBy = calculateCheckpointsHitbox().position - getPosition();
    if(mBy != sf::Vector2f{})
        moveBy = mBy.normalized();

    setRotation(moveBy.angle());
}

sf::FloatRect Enemy::calculateCheckpointsHitbox() const
{
    auto center = currentCheckpoint->getGlobalBounds().getCenter();
    sf::FloatRect rect{center, currentCheckpoint->getGlobalBounds().size / 10.f};
    rect.position -= rect.size / 2.f;

    return rect;
}
