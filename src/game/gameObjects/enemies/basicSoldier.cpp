#include "basicSoldier.hpp"

BasicSoldier::BasicSoldier(Checkpoint::Iterator _checkpoint)
    : Enemy(util::AssetLoader::get().basicSoldier, _checkpoint, EnemyType::BasicSoldier)
{}