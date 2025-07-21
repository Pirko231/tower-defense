#pragma once
#include "towerFactoryInterface.hpp"
#include "turrets/turret.hpp"
#include "assetloader.hpp"
#include "turrets/machineGun.hpp"

class MachineGunFactory : public ITowerFactory
{
public:
    MachineGunFactory() = default;
    ~MachineGunFactory() override = default;


    std::unique_ptr<Tower> create(IClientEnemyManager* eManager = nullptr) override
    {
        std::unique_ptr<Turret> turret = std::make_unique<MachineGun>();
        Tower tower(eManager, util::AssetLoader::get().towerBase, std::move(turret), TowerType::SingleCannon);
        return std::make_unique<Tower>(tower);
    }

};