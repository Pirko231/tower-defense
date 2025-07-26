#include "upgradeGUI.hpp"

UpgradeGUI::UpgradeGUI(Map* _map, TowerManagerProxy* _towerManager, int* _money)
    : map(_map), towerManager(_towerManager), money(_money), upgradeButton(util::AssetLoader::get().font)
{
    background.setSize({320.f,150.f});
    background.setFillColor(sf::Color{51,204,255});

    upgradeButton.setString("UPGRADE");
    upgradeButton.setBackgroundSize({upgradeButton.getGlobalBounds().size.x, upgradeButton.getGlobalBounds().size.y * 2.f});
    upgradeButton.setScale({1.5f,1.5f}); 
    upgradeButton.setPosition({background.getSize().x / 2.f - upgradeButton.getGlobalBounds().size.x / 2.f,background.getSize().y - upgradeButton.getGlobalBounds().size.y * 2.f});
    upgradeButton.setFillColor(sf::Color::Red);

}

bool UpgradeGUI::click(sf::Vector2i mousePos)
{
    if(!tower)
        return false;

    sf::Vector2f pos = static_cast<sf::Vector2f>(mousePos);
    if(!getGlobalBounds().contains(pos))
        return false; // kliknieto nie w przycisk

    pos -= getPosition(); // przechodzimy na lokalne koordynaty
    if(upgradeButton.getGlobalBounds().contains(pos))
    {
        Turret::Stats stats{1.f, 1.5f};

        if(*money >= tower->getUpgradePrice())
        {
            *money -= tower->getUpgradePrice();
            tower->upgrade(stats, 1.5f);
            return true;
        }
    }
    
    return false;
}