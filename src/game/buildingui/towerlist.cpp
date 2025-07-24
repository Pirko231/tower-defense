#include "towerlist.hpp"

TowerList::TowerList(Map* _map, const int* _money, const int* _health)
    : map(_map), money(_money), health(_health),
    moneyIcon(util::AssetLoader::get().coinIcon), moneyText(util::AssetLoader::get().font),
    healthIcon(util::AssetLoader::get().healthIcon), healthText(util::AssetLoader::get().font)
{
    sf::Vector2f size = {util::mapSize.x * util::tileSize.x, util::mapSize.y * util::tileSize.y};
    background.setSize({size.x / 3.f, size.y});
    background.setFillColor({255,255,255,120});

    moneyIcon.setPosition({0.f,-10.f});
    moneyText.setPosition({moneyIcon.getPosition().x + moneyIcon.getGlobalBounds().size.x * 1.2f,moneyIcon.getPosition().y + 10.f});

    healthIcon.setPosition({220.f, 5.f});
    healthText.setPosition({healthIcon.getPosition().x + healthIcon.getGlobalBounds().size.x * 1.5f, healthIcon.getPosition().y});



    products.push_back(Product(std::make_unique<SingleCannonFactory>(), {0.f,50.f}));

    products.push_back(Product(std::make_unique<DoubleCannonFactory>(), {0.f, 120.f}));

    products.push_back(Product(std::make_unique<MachineGunFactory>(), {0.f,190.f}));    

    products.push_back(Product(std::make_unique<RocketLauncherFactory>(), {0.f,260.f})); 
}

void TowerList::setVisible(sf::Vector2i mousePos, bool _visible)
{
    visible = _visible;
    auto tile = map->findTile(mousePos);

    sf::Vector2f size = {util::mapSize.x * util::tileSize.x, util::mapSize.y * util::tileSize.y};
    if (tile->getPosition().x >= size.x / 2.f)
    {
        background.setPosition({0.f,0.f});
        for (auto& product : products)
            product.setPosition({0.f, product.getPosition().y});
        moneyText.setPosition({0.f + moneyIcon.getGlobalBounds().size.x * 1.2f,moneyText.getPosition().y});
        moneyIcon.setPosition({0.f,moneyIcon.getPosition().y});
    
        healthIcon.setPosition({220.f, 5.f});
        healthText.setPosition({healthIcon.getPosition().x + healthIcon.getGlobalBounds().size.x * 1.5f, healthIcon.getPosition().y});
    }
    else
    {
        background.setPosition({size.x - background.getGlobalBounds().size.x,0.f});
        for (auto& product : products)
            product.setPosition({size.x - background.getGlobalBounds().size.x , product.getPosition().y});
        moneyText.setPosition({size.x - background.getGlobalBounds().size.x + moneyIcon.getGlobalBounds().size.x * 1.2f, moneyText.getPosition().y});
        moneyIcon.setPosition({size.x - background.getGlobalBounds().size.x, moneyIcon.getPosition().y});
    
        healthIcon.setPosition({size.x - background.getGlobalBounds().size.x + 220.f, 5.f});
        healthText.setPosition({size.x - background.getGlobalBounds().size.x + 220.f + healthIcon.getGlobalBounds().size.x * 1.5f, healthIcon.getPosition().y});
    }
}

const Product* TowerList::click(sf::Vector2i mousePos)
{
    if (!background.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
        return nullptr;

    for (auto& product : products)
        if (product.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
        {
            return &product;
        }

    return nullptr;
}
