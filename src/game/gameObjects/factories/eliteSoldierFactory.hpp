#pragma once
#include "enemyfactoryinterface.hpp"
#include "../enemies/eliteSoldier.hpp"

class EliteSoldierFactory : public IEnemyFactory
{
public:
    EliteSoldierFactory() = default;
    
    std::unique_ptr<Enemy> create(Checkpoint::Iterator checkpoint) const override
    {
        auto s = std::make_unique<EliteSoldier>(checkpoint);
        
        s->calculateMoveBy();

        return s;
    }
};