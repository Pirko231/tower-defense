#pragma once
#include "button.hpp"
#include <SFML/Graphics.hpp>

namespace btn
{

class MapButton : public Button
{
    sf::Text text;
    sf::RectangleShape background;
    std::filesystem::path mapPath;
public:
    MapButton(const sf::Font& font, const std::filesystem::path& mapName);

    sf::FloatRect getGlobalBounds() const override {return sf::FloatRect{getPosition(),background.getGlobalBounds().size};}

    const std::filesystem::path& getMap() const {return mapPath;}

    void update() override;

    bool isPressed(sf::Vector2i mousePos) const override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override
    {
        target.draw(background, states);

        target.draw(text, states);
    }
};

} // btn
