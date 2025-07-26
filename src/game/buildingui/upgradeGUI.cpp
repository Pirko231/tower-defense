#include "upgradeGUI.hpp"

UpgradeGUI::UpgradeGUI(Map* _map, TowerManagerProxy* _towerManager)
    : map(_map), towerManager(_towerManager), upgradeButton(util::AssetLoader::get().font)
{
    background.setSize({320.f,150.f});
    background.setFillColor(sf::Color{51,204,255});

    upgradeButton.setString("UPGRADE");
    upgradeButton.setPosition({background.getSize().x / 2.f - upgradeButton.getGlobalBounds().size.x / 2.f,background.getSize().y - upgradeButton.getGlobalBounds().size.y * 2.f});
}

void UpgradeGUI::click(sf::Vector2i mousePos)
{
    sf::Vector2f pos = static_cast<sf::Vector2f>(mousePos);
    if(!background.getGlobalBounds().contains(pos))
        return; // kliknieto nie w przycisk
    

}