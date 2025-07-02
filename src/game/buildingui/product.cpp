//
// Created by szymek on 01.07.25.
//

#include "product.hpp"

Product::Product(ITowerFactory* towerFactory, int _price, sf::Vector2f position)
    : price(_price), tower(std::move(towerFactory->create()))
{
    background.setFillColor(sf::Color{0,50,50,100});
    background.setSize({420.f,65.f});

    background.setPosition(position);
    tower->setPosition(position);
}
