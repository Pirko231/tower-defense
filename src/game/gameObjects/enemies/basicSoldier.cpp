#include "basicSoldier.hpp"

BasicSoldier::BasicSoldier(const sf::Texture &_texture, Checkpoint::Iterator _checkpoint)
    : Enemy(_texture, _checkpoint, 5)
{
}