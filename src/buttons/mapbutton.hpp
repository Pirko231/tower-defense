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
    int health;
    int money;
public:
    MapButton(const sf::String& mapName, const std::filesystem::path& mapPath, const std::filesystem::path& enemyName, int decorationAmount, int _health, int _money);

    MapButton(MapInfo::MapData data);
    
    sf::FloatRect getGlobalBounds() const override {return sf::FloatRect{getPosition(),background.getGlobalBounds().size};}

    const std::filesystem::path& getMap() const {return mapPath;}

    const std::filesystem::path& getEnemies() const {return enemyPath;}

    int getDecorationAmount() const {return decorationAmount;}

    int getHealth() const {return health;}

    int getMoney() const {return money;}

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
