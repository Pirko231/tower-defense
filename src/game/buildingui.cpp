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


    static Tower* tower{};
    
    auto tile = map->findTile(where);
    sf::Vector2f previousPos{getMapPointerPosition()};
    if(auto bp = map->getBuildPoint((sf::Vector2i)previousPos); bp)
        tower = map->getBuildPoint((sf::Vector2i)previousPos)->getTower();
    mapPointer.setPosition(tile->getPosition());

    if(upgradeGUI.getGlobalBounds().contains(static_cast<sf::Vector2f>(where)) && tower)
    {
        /*if(upgradeGUI.isVisible())
        {
        
            if (upgradeGUI.click(where, previousPos))
            {
                leaveBuildMode();
                return;
            }
            
        }*/
       if(upgradeGUI.getBin(where))
       {
            *money += towerManager->destructTowers(previousPos) / 2;
            leaveBuildMode();
            mapPointer.setPosition(previousPos);
       }

       if(upgradeGUI.getUpgrade(where))
       {
            if(tower->canUpgrade() && *money >= tower->getUpgradePrice())
            {
                *money -= tower->getUpgradePrice();
                tower->upgrade();
                upgradeGUI.refresh();
                mapPointer.setPosition(previousPos);
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
