#pragma once
#include <SFML/Graphics.hpp>
#include "map.hpp"
#include "buildingui/towerlist.hpp"
#include "gameObjects/managers/towermanagerproxy.hpp"

class BuildingUI : public sf::Drawable
{
    Map* map{};
    TowerManagerProxy* towerManager{};
    TowerList towerList;

    sf::RectangleShape mapPointer;
    bool mapPointerVisible{};

    int* money{};
public:
    BuildingUI(Map* _map, TowerManagerProxy* towerManager, int* _money);

    /// @brief przyjmuje pozycje myszy i ustawia kwadrat do klikneicia
    void click(sf::Vector2i where);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        if (mapPointerVisible)
        {
            target.draw(mapPointer, states);
        }
        target.draw(towerList, states);
    }
private:
    void buyProduct(const Product* product);
};
