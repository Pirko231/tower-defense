//
// Created by szymek on 30.06.25.
//

#include "textbutton.hpp"

namespace btn
{
    TextButton::TextButton(const sf::Font &font)
        : text(font)
    {
        text.setCharacterSize(25);
        text.setString("empty string");
    }

    void TextButton::update()
    {
    }

    bool TextButton::isPressed(sf::Vector2i mousePos) const
    {
        return getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    }
} // btn