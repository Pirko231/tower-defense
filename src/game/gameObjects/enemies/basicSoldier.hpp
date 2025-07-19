#pragma once
#include "enemy.hpp"

class BasicSoldier : public Enemy
{
public:
    BasicSoldier(const sf::Texture& _texture, Checkpoint::Iterator _checkpoint);
};