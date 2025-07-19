#include "basicSoldier.hpp"

namespace
{
    constexpr int maxSoldierHealth = 50;
    constexpr int soldierMoneyValue = 5;
    constexpr int soldierDamage = 5;
}

BasicSoldier::BasicSoldier(Checkpoint::Iterator _checkpoint)
    : Enemy(util::AssetLoader::get().basicSoldier, _checkpoint, soldierMoneyValue, maxSoldierHealth, soldierDamage)
{}