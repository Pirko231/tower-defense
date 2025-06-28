#pragma once

#include "towerFactoryInterface.hpp"
#include "archers/archer.hpp"
#include "assetloader.hpp"

class ArcherFactory : public ITowerFactory
{
public:
    ArcherFactory() = default;
    ~ArcherFactory() override = default;


    std::unique_ptr<Tower> create() override
    {
        std::unique_ptr<IArcher> archer = std::make_unique<Archer>(util::AssetLoader::get().archerTower.archer);
        Tower tower(util::AssetLoader::get().archerTower.tower, std::move(archer));
        return std::make_unique<Tower>(tower);
    }

};
