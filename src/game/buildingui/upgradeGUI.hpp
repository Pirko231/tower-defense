#pragma once
#include <SFML/Graphics.hpp>
#include "../../buttons/textbutton.hpp"
#include "../gameObjects/managers/towermanagerproxy.hpp"
#include "base.hpp"

class UpgradeGUI : public sf::Drawable, public sf::Transformable
{
    Map* map{};
    TowerManagerProxy* towerManager{};

    bool visible{};
    sf::RectangleShape background;
    btn::TextButton upgradeButton;
public:
    UpgradeGUI(Map* _map, TowerManagerProxy* _towerManager);

    /// @brief 
    /// @param mousePos 
    void click(sf::Vector2i mousePos);

    bool isVisible() const {return visible;}

    void setVisible(bool value) {visible = value;}

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        if(!visible)
            return;
        target.draw(background,states);
        target.draw(upgradeButton, states);
    }
};