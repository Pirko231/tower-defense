#pragma once
#include "towerFactoryInterface.hpp"
#include "turrets/turret.hpp"
#include "assetloader.hpp"
#include "turrets/doubleCannon.hpp"

class DoubleCannonFactory : public ITowerFactory
{
public:
    DoubleCannonFactory() = default;
    ~DoubleCannonFactory() override = default;


    std::unique_ptr<Tower> create(IClientEnemyManager* eManager = nullptr, IBulletManager* bManager = nullptr) override
    {
        std::unique_ptr<Turret> turret = std::make_unique<DoubleCannon>(bManager);
        Tower tower(eManager, util::AssetLoader::get().towerBase, std::move(turret), TowerType::DoubleCannon);
        return std::make_unique<Tower>(tower);
    }

};