#include "enemy.hpp"

Enemy::Enemy(const sf::Texture& _texture, Checkpoint::Iterator _checkpoint)
    : sprite(_texture), currentCheckpoint(_checkpoint)
{
    moveBy =  currentCheckpoint->getGlobalBounds().getCenter() - getPosition();
    if(moveBy != sf::Vector2f{})
        moveBy = moveBy.normalized();
    setRotation(moveBy.angle());
}

void Enemy::update()
{
    sprite.move(moveBy);

    if(hasReachedDestination())
        nextDestination();
}

void Enemy::nextDestination()
{
    if(!currentCheckpoint.hasNext())
        return;
    auto checkPoint = currentCheckpoint;
    currentCheckpoint++;

    sf::Vector2f mBy = currentCheckpoint->getGlobalBounds().getCenter() - checkPoint->getGlobalBounds().getCenter();
    if(mBy != sf::Vector2f{})
        moveBy = mBy.normalized();
}
