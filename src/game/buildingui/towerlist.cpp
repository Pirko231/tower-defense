#include "towerlist.hpp"

TowerList::TowerList(Map* _map)
    : map(_map)
{
    sf::Vector2f size = {util::mapSize.x * util::tileSize.x, util::mapSize.y * util::tileSize.y};
    background.setSize({size.x / 3.f, size.y});
    background.setFillColor({255,255,255,120});

    ArcherFactory archerFactory;
    products.push_back(Product(&archerFactory, 20, {30.f,0.f}));
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
