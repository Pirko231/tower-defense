//
// Created by szymek on 07.07.25.
//
#pragma once
#include <SFML/Graphics/Sprite.hpp>

#include "button.hpp"

namespace btn
{
    class PlayButton : public Button
    {
        sf::Sprite sprite;
    public:
        PlayButton();

        void update() override;

        bool isPressed(sf::Vector2i mousePos) const override;

        sf::FloatRect getGlobalBounds() const override {return sf::FloatRect{getPosition(), sprite.getGlobalBounds().size};}

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override
        {
            states.transform *= getTransform();

            target.draw(sprite, states);
        }
    };
};
