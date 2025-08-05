#include "mechaSoldier.hpp"


MechaSoldier::MechaSoldier(Checkpoint::Iterator checkpoint)
    : Enemy(util::AssetLoader::get().mechaSoldier, checkpoint, EnemyType::MechaSoldier)
{}