#pragma once
#include <SFML/Graphics.hpp>
#include "button.hpp"

namespace btn
{

class TextButton : public Button
{
    sf::Text text;
    sf::RectangleShape background;
public:
    TextButton(const sf::Font& font);

    void update() override;

    bool isPressed(sf::Vector2i mousePos) const override;

    sf::FloatRect getGlobalBounds() const override {return sf::FloatRect(getPosition(), {text.getGlobalBounds().size.x  * getScale().x, text.getGlobalBounds().size.y  * getScale().y} );}

    void setCharacterSize(unsigned int fontSize) {text.setCharacterSize(fontSize);}

    void setString(const sf::String& string) {text.setString(string);}

    void setFillColor(sf::Color color) {background.setFillColor(color);}

    void setBackgroundSize(sf::Vector2f size) {background.setSize(size);}

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        target.draw(background,states);
        target.draw(text,states);
    }
};

} // btn
