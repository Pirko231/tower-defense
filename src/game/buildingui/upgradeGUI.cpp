#include "upgradeGUI.hpp"

UpgradeGUI::UpgradeGUI(Map* _map, TowerManagerProxy* _towerManager, int* _money)
    : map(_map), towerManager(_towerManager), money(_money),
    upgradeButton(util::AssetLoader::get().font), 
    moneyUpgradeIcon(util::AssetLoader::get().coinIcon), moneyUpgradeText(util::AssetLoader::get().font), currentLevel(util::AssetLoader::get().font),
    bin(util::AssetLoader::get().binIcon),
    moneyBinIcon(util::AssetLoader::get().coinIcon), moneyBinText(util::AssetLoader::get().font),
    damageIcon(util::AssetLoader::get().attackIcon), damageText(util::AssetLoader::get().font),
    rangeIcon(util::AssetLoader::get().rangeIcon), rangeText(util::AssetLoader::get().font)
{
    background.setSize({320.f,150.f});
    background.setFillColor(sf::Color{51,204,255});

    bin.setPosition({getGlobalBounds().size.x - bin.getGlobalBounds().size.x, 0.f});

    upgradeButton.setString("UPGRADE");
    upgradeButton.setBackgroundSize({upgradeButton.getGlobalBounds().size.x, upgradeButton.getGlobalBounds().size.y * 2.f});
    upgradeButton.setScale({1.5f,1.5f}); 
    upgradeButton.setPosition({background.getSize().x - upgradeButton.getGlobalBounds().size.x,background.getSize().y - upgradeButton.getGlobalBounds().size.y * 2.f});
    upgradeButton.setFillColor(sf::Color::Red);

    currentLevel.setString("test");
    currentLevel.setPosition({});

    moneyUpgradeIcon.setPosition({0.f, upgradeButton.getPosition().y});
    moneyUpgradeText.setString("text");
    moneyUpgradeText.setPosition({moneyUpgradeIcon.getPosition().x + moneyUpgradeIcon.getGlobalBounds().size.x, upgradeButton.getPosition().y + moneyUpgradeText.getGlobalBounds().size.y / 2.f});

    moneyBinIcon.setPosition({bin.getPosition().x - moneyBinIcon.getGlobalBounds().size.x * 1.8f, 0.f - 10.f});
    moneyBinText.setString("test");
    moneyBinText.setPosition({moneyBinIcon.getPosition().x + 60.f, 0.f});

    damageIcon.setScale({0.8f,0.8f});
    damageIcon.setPosition({20.f, background.getSize().y / 2.f - damageIcon.getGlobalBounds().size.y / 1.5f});
    damageText.setString("test");
    damageText.setPosition({damageIcon.getPosition().x + damageIcon.getGlobalBounds().size.x, damageIcon.getPosition().y});

    rangeIcon.setScale({0.8f,0.8f});
    rangeIcon.setPosition({damageText.getPosition().x + damageText.getGlobalBounds().size.x * 2.5f, damageIcon.getPosition().y});
    rangeText.setString("test");
    rangeText.setPosition({rangeIcon.getPosition().x + rangeIcon.getGlobalBounds().size.x, damageIcon.getPosition().y});
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

        if(*money >= tower->getUpgradePrice())
        {
            *money -= tower->getUpgradePrice();
            tower->upgrade();
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
    currentLevel.setString(std::to_string(tower->getLevel() + 1) + "/" + std::to_string(tower->getMaxLevel() + 1));
    if(tower->getLevel() < tower->getMaxLevel())
        moneyUpgradeText.setString(std::to_string(tower->getUpgradePrice()));
    else
        moneyUpgradeText.setString("MAX");
    moneyBinText.setString(std::to_string(tower->getPrice() / 2));

    damageText.setString(std::format("{0:.2f}/s", tower->getDPS()));
    rangeText.setString(std::format("{0:.0f}", tower->getRange()));
}
