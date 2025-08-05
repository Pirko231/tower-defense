#include "eliteSoldier.hpp"


EliteSoldier::EliteSoldier(Checkpoint::Iterator checkpoint)
    : Enemy(util::AssetLoader::get().eliteSoldier, checkpoint,EnemyType::EliteSoldier)
{
    setScale({0.7f,0.7f});
}