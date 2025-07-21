#include "eliteSoldier.hpp"

namespace
{
    constexpr int soldierMoneyValue = 10;
    constexpr int maxSoldierHealth = 150;
    constexpr int soldierDamage = 15;
    constexpr float soldierSpeed = 1.f;
}


EliteSoldier::EliteSoldier(Checkpoint::Iterator checkpoint)
    : Enemy(util::AssetLoader::get().eliteSoldier, checkpoint, soldierMoneyValue, maxSoldierHealth, soldierDamage, soldierSpeed)
{
    setScale({0.7f,0.7f});
}