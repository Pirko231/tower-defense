#include "superSoldier.hpp"

SuperSoldier::SuperSoldier(Checkpoint::Iterator checkpoint)
    : Enemy(util::AssetLoader::get().superSoldier, checkpoint, EnemyType::SuperSoldier)
{
    setScale({0.65f,0.65f});
}