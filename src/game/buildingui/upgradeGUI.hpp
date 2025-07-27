#pragma once
#include <SFML/Graphics.hpp>
#include "../../buttons/textbutton.hpp"
#include "../gameObjects/managers/towermanagerproxy.hpp"
#include "base.hpp"

class UpgradeGUI : public sf::Drawable, public sf::Transformable
{
    Map* map{};
    TowerManagerProxy* towerManager{};
    int* money{};

    bool visible{};
    Tower* tower{};
    sf::RectangleShape background;
    btn::TextButton upgradeButton;

    sf::Sprite bin;
    sf::Sprite moneyBinIcon;
    sf::Text moneyBinText;

    sf::Sprite damageIcon;
    sf::Text damageText;

    sf::Sprite rangeIcon;
    sf::Text rangeText;
public:
    UpgradeGUI(Map* _map, TowerManagerProxy* _towerManager, int* _money);

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect{getPosition(), background.getSize()};}

    /// @brief 
    /// @param mousePos 
    /// @return czy kliknieto w kwadrat
    bool click(sf::Vector2i mousePos, sf::Vector2f mapPointerPos);

    bool isVisible() const {return visible;}

    void setVisible(bool value, Tower* _tower)
    {visible = value; tower = _tower; if(tower) setTextsData();}

    Tower* getCurrentTower() const {return tower;}


    void setInterfacePosition(sf::Vector2f mapPointerPos);
private:
    void setTextsData();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        if(!visible)
            return;
        target.draw(background,states);
        target.draw(upgradeButton, states);
        target.draw(bin,states);
        target.draw(moneyBinIcon,states);
        target.draw(moneyBinText,states);
        target.draw(damageIcon,states);
        target.draw(damageText,states);
        target.draw(rangeIcon,states);
        target.draw(rangeText,states);
    }
};