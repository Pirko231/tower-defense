#pragma once
#include <SFML/Graphics.hpp>


class HealthBar : public sf::Drawable, public sf::Transformable
{
    int maxHealth{};

    sf::RectangleShape background;
    sf::RectangleShape current;
public:
    HealthBar(int maxHealth);

    void update(int health);

    void setMax(int max) {maxHealth = max;}

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect{getPosition(), background.getSize()};}

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        target.draw(background, states);
        target.draw(current, states);
    }
};