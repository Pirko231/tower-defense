#pragma once

#include "towerFactoryInterface.hpp"
#include "turrets/turret.hpp"
#include "assetloader.hpp"

class ArcherFactory : public ITowerFactory
{
public:
    ArcherFactory() = default;
    ~ArcherFactory() override = default;


    std::unique_ptr<Tower> create(IClientEnemyManager* eManager = nullptr) override
    {
        std::unique_ptr<ITurret> archer = std::make_unique<Turret>(util::AssetLoader::get().cannon1);
        archer->setRange(250.f);
        Tower tower(eManager, util::AssetLoader::get().towerBase, std::move(archer), TowerType::Archer);
        return std::make_unique<Tower>(tower);
    }

};
