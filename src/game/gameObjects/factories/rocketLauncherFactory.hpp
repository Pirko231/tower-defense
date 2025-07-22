#pragma once

#include "towerFactoryInterface.hpp"
#include "turrets/turret.hpp"
#include "assetloader.hpp"
#include "turrets/rocketLauncher.hpp"

class RocketLauncherFactory : public ITowerFactory
{
public:
    RocketLauncherFactory() = default;
    ~RocketLauncherFactory() override = default;


    std::unique_ptr<Tower> create(IClientEnemyManager* eManager = nullptr, IBulletManager* bManager = nullptr) override
    {
        std::unique_ptr<Turret> turret = std::make_unique<RocketLauncher>(bManager);
        Tower tower(eManager, util::AssetLoader::get().towerBase, std::move(turret), TowerType::RocketLauncher);
        return std::make_unique<Tower>(tower);
    }

};
