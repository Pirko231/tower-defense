#pragma once
#include "../enemies/basicSoldier.hpp"
#include "base.hpp"

class BasicSoldierFactory : public IEnemyFactory
{
public:
    BasicSoldierFactory() = default;
    
    std::unique_ptr<Enemy> create(Checkpoint::Iterator checkpoint) const override
    {
        auto s = std::make_unique<BasicSoldier>(checkpoint);
        
        s->setDamage(5);
        s->calculateMoveBy();

        return s;
    }
};