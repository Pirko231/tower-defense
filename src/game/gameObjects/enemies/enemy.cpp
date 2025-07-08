#include "enemy.hpp"

Enemy::Enemy(const sf::Texture& _texture, Checkpoint::Iterator _checkpoint)
    : sprite(_texture), currentCheckpoint(_checkpoint)
{
    setOrigin(getGlobalBounds().getCenter());

    moveBy =  currentCheckpoint->getGlobalBounds().getCenter() - getPosition();
    if(moveBy != sf::Vector2f{})
        moveBy = moveBy.normalized();
    setRotation(moveBy.angle());
}

void Enemy::update()
{
    move(moveBy);

    if(hasReachedDestination())
        nextDestination();
}

void Enemy::nextDestination()
{
    if(!currentCheckpoint.hasNext())
        return;
    currentCheckpoint++;

    sf::Vector2f mBy = currentCheckpoint->getGlobalBounds().getCenter() - getPosition();
    if(mBy != sf::Vector2f{})
        moveBy = mBy.normalized();

    setRotation(moveBy.angle());
}
