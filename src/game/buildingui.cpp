#include "buildingui.hpp"

BuildingUI::BuildingUI(Map *_map, TowerManagerProxy* _towerManager, int* _money, int* _health)
    : map(_map), money(_money), health(_health), towerManager(_towerManager), towerList(_map, money, health)
{
    mapPointer.setFillColor({20,20,100,80});
    mapPointer.setSize(static_cast<sf::Vector2f>(util::tileSize));
}

void BuildingUI::click(sf::Vector2i where)
{
    if (towerList.isVisible())
    {
        auto product = towerList.click(where);
        if (product)
        {
            buyProduct(product);
            towerList.setVisible({0,0}, false);
            mapPointerVisible = false;
            return;
        }
    }

    auto tile = map->findTile(where);

    mapPointer.setPosition(tile->getPosition());

    towerList.setVisible(where, true);

    mapPointerVisible = true;
}

void BuildingUI::buyProduct(const Product *product)
{
    if (product->getPrice() > *money)
        return; //nie stac nas na zakup


    if (towerManager->addTower(util::calculatePosition(mapPointer.getPosition()), product->getFactory()))
        *money -= product->getPrice();
}
