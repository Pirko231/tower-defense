#pragma once

#include "towerFactoryInterface.hpp"
#include "turrets/turret.hpp"
#include "assetloader.hpp"
#include "turrets/singleCannon.hpp"

class SingleCannonFactory : public ITowerFactory
{
public:
    SingleCannonFactory() = default;
    ~SingleCannonFactory() override = default;


    std::unique_ptr<Tower> create(IClientEnemyManager* eManager = nullptr, IBulletManager* bManager = nullptr) override
    {
        std::unique_ptr<Turret> turret = std::make_unique<SingleCannon>(bManager);
        Tower tower(eManager, util::AssetLoader::get().towerBase, std::move(turret), TowerType::SingleCannon, price);
        return std::make_unique<Tower>(std::move(tower));
    }
private:
    constexpr static int price = 30;
};
