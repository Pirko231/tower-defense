#pragma once
#include "SFML/Graphics.hpp"
#include "base.hpp"

class PauseMenu : public sf::Drawable, public sf::Transformable
{
    sf::Sprite background;
public:
    PauseMenu();

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect{getPosition(),background.getGlobalBounds().size};}

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        target.draw(background,states);
    }
};