#pragma once

#include "enemyfactoryinterface.hpp"
#include "../enemies/superSoldier.hpp"
#include "base.hpp"

class SuperSoldierFactory : public IEnemyFactory
{
public:
    SuperSoldierFactory() = default;
    
    std::unique_ptr<Enemy> create(Checkpoint::Iterator checkpoint) const override
    {
        auto s = std::make_unique<SuperSoldier>(checkpoint);
        
        s->calculateMoveBy();

        return s;
    }
};