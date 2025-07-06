//
// Created by szymek on 01.07.25.
//

#include "product.hpp"

#include "assetloader.hpp"

Product::Product(std::unique_ptr<ITowerFactory> _towerFactory, int _price, sf::Vector2f position)
    : price(_price), tower(std::move(_towerFactory->create())), towerFactory(std::move(_towerFactory)),
    attackIcon(util::AssetLoader::get().attackIcon), attackText(util::AssetLoader::get().font),
    coinIcon(util::AssetLoader::get().coinIcon), coinText(util::AssetLoader::get().font)
{
    background.setFillColor(sf::Color{0,50,50,100});
    background.setSize({420.f,65.f});

    background.setPosition(position);
    tower->setPosition(position);

    attackIcon.setScale({0.7f, 0.7f});
    attackIcon.setPosition({position.x + tower->getGlobalBounds().size.x, position.y + background.getSize().y / 2.f - attackIcon.getGlobalBounds().size.y / 2.f});

    coinIcon.setPosition({attackIcon.getPosition().x + attackIcon.getGlobalBounds().size.x * 2.5f, position.y + background.getSize().y / 2.f - coinIcon.getGlobalBounds().size.y / 2.f});

    coinText.setString(std::to_string(price));
    coinText.setPosition({coinIcon.getPosition().x + coinIcon.getGlobalBounds().size.x * 1.2f, position.y + background.getSize().y / 2.f - coinText.getGlobalBounds().size.y / 1.f});

}
