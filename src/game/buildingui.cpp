#include "buildingui.hpp"

BuildingUI::BuildingUI(Map *_map, TowerManagerProxy* _towerManager, int* _money)
    : map(_map), towerManager(_towerManager), towerList(_map), money(_money)
{
    mapPointer.setFillColor({20,20,100,80});
    mapPointer.setSize(static_cast<sf::Vector2f>(util::tileSize));
}

void BuildingUI::click(sf::Vector2i where)
{
    if (towerList.isVisible())
    {
        auto opt = towerList.click(where);
        if (opt.has_value())
        {
            auto product = opt.value();

            buyProduct(product);
            towerList.setVisible({0,0}, false);
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

    *money -= product->getPrice();

    towerManager->addTower(static_cast<sf::Vector2i>(mapPointer.getPosition()), product->getType());
}
