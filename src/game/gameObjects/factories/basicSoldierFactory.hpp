#pragma once
#include "enemyfactoryinterface.hpp"
#include "base.hpp"

class BasicSoldierFactory : public IEnemyFactory
{
public:
    BasicSoldierFactory() = default;
    
    std::unique_ptr<Enemy> create() const override {return std::make_unique<Enemy>(Enemy{util::AssetLoader::get().basicSoldier});}
};