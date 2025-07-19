//
// Created by szymek on 01.07.25.
//

#include "product.hpp"
#include <format>
#include "assetloader.hpp"
#include "base.hpp"

Product::Product(std::unique_ptr<ITowerFactory> _towerFactory, int _price, sf::Vector2f position)
    : price(_price), tower(std::move(_towerFactory->create())), towerFactory(std::move(_towerFactory)),
    attackIcon(util::AssetLoader::get().attackIcon), attackText(util::AssetLoader::get().font),
    coinIcon(util::AssetLoader::get().coinIcon), coinText(util::AssetLoader::get().font)
{
    setPosition(position);

    background.setFillColor(sf::Color{0,50,50,100});
    background.setSize({util::mapSize.x * util::tileSize.x / 3.f,65.f});

    attackIcon.setScale({0.7f, 0.7f});
    attackIcon.setPosition({tower->getGlobalBounds().size.x, background.getSize().y / 2.f - attackIcon.getGlobalBounds().size.y / 2.f});

    attackText.setString(std::format("{0:.2f}/s", tower->getDPS()));
    attackText.setPosition({attackIcon.getPosition().x + attackIcon.getGlobalBounds().size.x * 1.2f, background.getSize().y / 2.f - attackIcon.getGlobalBounds().size.y / 2.f});

    coinIcon.setPosition({attackIcon.getPosition().x + attackIcon.getGlobalBounds().size.x * 2.5f, background.getSize().y / 2.f - coinIcon.getGlobalBounds().size.y / 2.f});

    coinText.setString(std::to_string(price));
    coinText.setPosition({coinIcon.getPosition().x + coinIcon.getGlobalBounds().size.x * 1.2f, background.getSize().y / 2.f - coinText.getGlobalBounds().size.y / 1.f});

}
