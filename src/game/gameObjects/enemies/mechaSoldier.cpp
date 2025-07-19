#include "mechaSoldier.hpp"

namespace
{
    static constexpr int soldierMoneyValue = 50;
    static constexpr int maxSoldierHealth = 300;
    static constexpr int soldierDamage = 50;
    static constexpr float soldierSpeed = 1.f;
}

MechaSoldier::MechaSoldier(Checkpoint::Iterator checkpoint)
    : Enemy(util::AssetLoader::get().mechaSoldier, checkpoint, soldierMoneyValue, maxSoldierHealth, soldierDamage, soldierSpeed)
{}