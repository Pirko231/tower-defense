#pragma once
#include "button.hpp"
#include <SFML/Graphics.hpp>

namespace btn
{

class MapButton : public Button
{
    sf::Text text;
    sf::Sprite background;
    std::filesystem::path mapPath;
    std::filesystem::path enemyPath;
public:
    MapButton(const sf::String& mapName, const std::filesystem::path& mapPath, const std::filesystem::path& enemyName);

    sf::FloatRect getGlobalBounds() const override {return sf::FloatRect{getPosition(),background.getGlobalBounds().size};}

    const std::filesystem::path& getMap() const {return mapPath;}

    const std::filesystem::path& getEnemies() const {return enemyPath;}

    void update() override;

    bool isPressed(sf::Vector2i mousePos) const override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        target.draw(background, states);

        target.draw(text, states);
    }
};

} // btn
