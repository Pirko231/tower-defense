#include "superSoldier.hpp"

namespace
{
    static constexpr int soldierMoneyValue = 15;
    static constexpr int maxSoldierHealth = 150;
    static constexpr int soldierDamage = 20;
    constexpr int soldierShield = 3;
    static constexpr float soldierSpeed = 2.f;
}

SuperSoldier::SuperSoldier(Checkpoint::Iterator checkpoint)
    : Enemy(util::AssetLoader::get().superSoldier, checkpoint, soldierMoneyValue, maxSoldierHealth, soldierDamage, soldierShield, soldierSpeed)
{
    setScale({0.65f,0.65f});
}