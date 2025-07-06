#include "towerlist.hpp"

TowerList::TowerList(Map* _map, const int* _money)
    : map(_map), money(_money), moneyIcon(util::AssetLoader::get().coinIcon), moneyText(util::AssetLoader::get().font)
{
    sf::Vector2f size = {util::mapSize.x * util::tileSize.x, util::mapSize.y * util::tileSize.y};
    background.setSize({size.x / 3.f, size.y});
    background.setFillColor({255,255,255,120});

    ArcherFactory archerFactory;
    products.push_back(Product(std::make_unique<ArcherFactory>(), 20, {0.f,50.f}));

    moneyIcon.setPosition({0.f,-10.f});
    moneyText.setPosition({moneyIcon.getPosition().x + moneyIcon.getGlobalBounds().size.x * 1.2f,moneyIcon.getPosition().y + 10.f});
}

void TowerList::setVisible(sf::Vector2i mousePos, bool _visible)
{
    visible = _visible;
    auto tile = map->findTile(mousePos);

    sf::Vector2f size = {util::mapSize.x * util::tileSize.x, util::mapSize.y * util::tileSize.y};
    if (tile->getPosition().x >= size.x / 2.f)
        background.setPosition({0.f,0.f});
    else
        background.setPosition({size.x - background.getGlobalBounds().size.x,0.f});
}

std::optional<const Product*> TowerList::click(sf::Vector2i mousePos)
{
    if (!background.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
        return std::nullopt;

    for (auto& product : products)
        if (product.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
        {
            return &product;
        }

    return std::nullopt;
}
