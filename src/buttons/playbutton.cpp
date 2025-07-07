//
// Created by szymek on 07.07.25.
//

#include "playbutton.hpp"

#include "assetloader.hpp"

btn::PlayButton::PlayButton()
    : sprite(util::AssetLoader::get().playButton)
{
}

void btn::PlayButton::update()
{
}

bool btn::PlayButton::isPressed(sf::Vector2i mousePos) const
{
    if (getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
        return true;
    return false;
}
