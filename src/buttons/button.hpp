#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>


namespace btn
{

class Button : public sf::Drawable, public sf::Transformable
{
public:
    virtual void update() = 0;

    virtual bool isPressed(sf::Vector2i mousePos) const = 0;

    virtual sf::FloatRect getGlobalBounds() const = 0;
};

} // btn
