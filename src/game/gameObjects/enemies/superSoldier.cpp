#include "superSoldier.hpp"

namespace
{
    static constexpr int soldierMoneyValue = 15;
    static constexpr int maxSoldierHealth = 120;
    static constexpr int soldierDamage = 20;
    static constexpr float soldierSpeed = 1.f;
}

SuperSoldier::SuperSoldier(Checkpoint::Iterator checkpoint)
    : Enemy(util::AssetLoader::get().superSoldier, checkpoint, soldierMoneyValue, maxSoldierHealth, soldierDamage, soldierSpeed)
{
    setScale({0.65f,0.65f});
}