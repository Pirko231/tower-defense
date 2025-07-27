#include "upgradeGUI.hpp"

UpgradeGUI::UpgradeGUI(Map* _map, TowerManagerProxy* _towerManager, int* _money)
    : map(_map), towerManager(_towerManager), money(_money),
    upgradeButton(util::AssetLoader::get().font), bin(util::AssetLoader::get().binIcon),
    moneyBinIcon(util::AssetLoader::get().coinIcon), moneyBinText(util::AssetLoader::get().font)
{
    background.setSize({320.f,150.f});
    background.setFillColor(sf::Color{51,204,255});

    bin.setPosition({getGlobalBounds().size.x - bin.getGlobalBounds().size.x, 0.f});

    upgradeButton.setString("UPGRADE");
    upgradeButton.setBackgroundSize({upgradeButton.getGlobalBounds().size.x, upgradeButton.getGlobalBounds().size.y * 2.f});
    upgradeButton.setScale({1.5f,1.5f}); 
    upgradeButton.setPosition({background.getSize().x / 2.f - upgradeButton.getGlobalBounds().size.x / 2.f,background.getSize().y - upgradeButton.getGlobalBounds().size.y * 2.f});
    upgradeButton.setFillColor(sf::Color::Red);

    moneyBinIcon.setPosition({bin.getPosition().x - moneyBinIcon.getGlobalBounds().size.x * 1.8f, 0.f - 10.f});
    moneyBinText.setString("test");
    moneyBinText.setPosition({moneyBinIcon.getPosition().x + 60.f, 0.f});
}

bool UpgradeGUI::click(sf::Vector2i mousePos, sf::Vector2f mapPointerPos)
{
    // ustawienie pozycji interfejsu
    setInterfacePosition(mapPointerPos);

    if(!tower)
        return false;


    sf::Vector2f pos = static_cast<sf::Vector2f>(mousePos);
    pos -= getPosition(); // przechodzimy na lokalne koordynaty
    if(!background.getGlobalBounds().contains(pos))
        return false; // kliknieto nie w przycisk

    if(bin.getGlobalBounds().contains(pos))
    {
        *money += towerManager->destructTowers(mapPointerPos) / 2;
    }

    if(upgradeButton.getGlobalBounds().contains(pos))
    {
        Turret::Stats stats{1.f, 1.5f};

        if(*money >= tower->getUpgradePrice())
        {
            *money -= tower->getUpgradePrice();
            tower->upgrade(stats, 1.5f);
        }
    }
    
    return true;
}

void UpgradeGUI::setInterfacePosition(sf::Vector2f mapPointerPos)
{
    sf::Vector2f pos;
    if(mapPointerPos.x < util::mapSize.x * util::tileSize.x / 2)
        pos.x = 0.f;
    else
        pos.x = util::mapSize.x * util::tileSize.x - getGlobalBounds().size.x;

    setPosition(pos);
}

void UpgradeGUI::setTextsData()
{
    moneyBinText.setString(std::to_string(tower->getPrice() / 2));
}
