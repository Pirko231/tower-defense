#include "buildingui.hpp"

BuildingUI::BuildingUI(Map *_map, TowerManagerProxy* _towerManager, int* _money, int* _health)
    : map(_map), money(_money), health(_health), towerManager(_towerManager),
    towerList(_map, money, health), upgradeGUI(map,towerManager, money)
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
            leaveBuildMode();
            mapPointerVisible = false;
            return;
        }
    }


    Tower* tower{};
    
    auto tile = map->findTile(where);
    sf::Vector2f previousPos{getMapPointerPosition()};
    mapPointer.setPosition(tile->getPosition());

    if(upgradeGUI.getGlobalBounds().contains(static_cast<sf::Vector2f>(where)))
    {
        if(upgradeGUI.isVisible())
        {
        
            if (upgradeGUI.click(where, previousPos))
            {
                leaveBuildMode();
                return;
            }
            
        }

    }
    else
        if(BuildPoint* bp = map->getBuildPoint(util::calculatePosition(static_cast<sf::Vector2f>(where))))
        {
            if((tower = bp->getTower()))
            {
                upgradeGUI.setVisible(true, tower);
                upgradeGUI.setInterfacePosition(tower->getPosition());
            }
            else
            {
                upgradeGUI.setVisible(false,tower);
            }
        }
        else
        {
            upgradeGUI.setVisible(false,tower);
        }

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
