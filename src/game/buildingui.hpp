#pragma once
#include <SFML/Graphics.hpp>
#include "map.hpp"
#include "buildingui/towerlist.hpp"
#include "gameObjects/managers/towermanagerproxy.hpp"
#include "buildingui/upgradeGUI.hpp"

class BuildingUI : public sf::Drawable
{
    Map* map{};
    int* money{};
    int* health{};
    TowerManagerProxy* towerManager{};
    TowerList towerList;
    UpgradeGUI upgradeGUI;

    sf::RectangleShape mapPointer;
    bool mapPointerVisible{};
public:
    BuildingUI(Map* _map, TowerManagerProxy* towerManager, int* _money, int* _health);

    /// @brief przyjmuje pozycje myszy i ustawia kwadrat do klikneicia
    void click(sf::Vector2i where);

    void leaveBuildMode() {mapPointerVisible = false; towerList.setVisible({},false); upgradeGUI.setVisible(false);}

    sf::Vector2f getMapPointerPosition() const {return mapPointer.getPosition();}
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        if (mapPointerVisible)
        {
            target.draw(mapPointer, states);
        }
        target.draw(towerList, states);
        target.draw(upgradeGUI, states);
    }

    void buyProduct(const Product* product);
};
