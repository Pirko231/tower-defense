#include "basicSoldier.hpp"

namespace
{
    constexpr int soldierMoneyValue = 2;
    constexpr int maxSoldierHealth = 50;
    constexpr int soldierDamage = 5;
    constexpr float soldierSpeed = 1.f;
}

BasicSoldier::BasicSoldier(Checkpoint::Iterator _checkpoint)
    : Enemy(util::AssetLoader::get().basicSoldier, _checkpoint, soldierMoneyValue, maxSoldierHealth, soldierDamage, soldierSpeed)
{}