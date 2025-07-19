#pragma once
#include "enemyfactoryinterface.hpp"
#include "../enemies/mechaSoldier.hpp"
#include "base.hpp"

class MechaSoldierFactory : public IEnemyFactory
{
public:
    MechaSoldierFactory() = default;
    
    std::unique_ptr<Enemy> create(Checkpoint::Iterator checkpoint) const override
    {
        auto s = std::make_unique<MechaSoldier>(checkpoint);
        
        s->calculateMoveBy();

        return s;
    }
};