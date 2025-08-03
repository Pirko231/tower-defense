#pragma once
#include "SFML/Graphics.hpp"
#include "base.hpp"

class PauseMenu : public sf::Drawable, public sf::Transformable
{
    sf::Sprite background;

    sf::Sprite quit;
public:
    PauseMenu();

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect{getPosition(),{background.getGlobalBounds().size.x * getScale().x, background.getGlobalBounds().size.y * getScale().y}};}

    /// @brief zwraca czy powinno sie wyjsc do ekranu glownego
    /// @param mousePos pozycja myszki - kiedy najezdza na przycisk to wyjsc
    /// @return czy najezdza na przycisk
    bool getQuit(sf::Vector2i mousePos) const
    {
        sf::Vector2f localCords = (sf::Vector2f)mousePos - getPosition();
        sf::FloatRect rect{{quit.getPosition().x * getScale().x, quit.getPosition().y * getScale().y}, {quit.getLocalBounds().size.x * getScale().x, quit.getLocalBounds().size.y * getScale().y}};
        return rect.contains(localCords);
    }
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        target.draw(background,states);
        target.draw(quit,states);
    }
};