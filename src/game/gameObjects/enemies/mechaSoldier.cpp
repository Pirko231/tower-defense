#include "mechaSoldier.hpp"

namespace
{
    static constexpr int soldierMoneyValue = 20;
    static constexpr int maxSoldierHealth = 300;
    static constexpr int soldierDamage = 50;
    constexpr int soldierShield = 5;
    static constexpr float soldierSpeed = 0.5f;
}

MechaSoldier::MechaSoldier(Checkpoint::Iterator checkpoint)
    : Enemy(util::AssetLoader::get().mechaSoldier, checkpoint, soldierMoneyValue, maxSoldierHealth, soldierDamage, soldierShield, soldierSpeed)
{}