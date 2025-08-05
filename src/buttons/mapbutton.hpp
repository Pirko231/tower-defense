#pragma once
#include "button.hpp"
#include <SFML/Graphics.hpp>
#include "mapInfo.hpp"

namespace btn
{

class MapButton : public Button
{
    sf::Text text;
    sf::Sprite background;
    std::filesystem::path mapPath;
    std::filesystem::path enemyPath;
    int decorationAmount;
public:
    MapButton(const sf::String& mapName, const std::filesystem::path& mapPath, const std::filesystem::path& enemyName, int decorationAmount);

    MapButton(MapInfo::MapData data);
    
    sf::FloatRect getGlobalBounds() const override {return sf::FloatRect{getPosition(),background.getGlobalBounds().size};}

    const std::filesystem::path& getMap() const {return mapPath;}

    const std::filesystem::path& getEnemies() const {return enemyPath;}

    int getDecorationAmount() const {return decorationAmount;}

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
