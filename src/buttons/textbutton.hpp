#pragma once
#include <SFML/Graphics.hpp>
#include "button.hpp"

namespace btn
{

class TextButton : public Button
{
    sf::Text text;
public:
    TextButton(const sf::Font& font);

    void update() override;

    bool isPressed(sf::Vector2i mousePos) const override;

    sf::FloatRect getGlobalBounds() const override {return sf::FloatRect(getPosition(), text.getGlobalBounds().size);}

    void setCharacterSize(unsigned int fontSize) {text.setCharacterSize(fontSize);}

    void setString(const sf::String& string) {text.setString(string);}

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        target.draw(text,states);
    }
};

} // btn
