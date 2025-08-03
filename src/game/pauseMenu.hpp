#pragma once
#include "SFML/Graphics.hpp"
#include "base.hpp"

class PauseMenu : public sf::Drawable, public sf::Transformable
{
    sf::Sprite background;

    sf::Sprite quit;
    sf::Sprite restart;
    sf::Sprite cont; // continue
public:
    PauseMenu();

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect{getPosition(),{background.getGlobalBounds().size.x * getScale().x, background.getGlobalBounds().size.y * getScale().y}};}

    /// @brief zwraca czy powinno sie wyjsc do ekranu glownego
    /// @param mousePos pozycja myszki - kiedy najezdza na przycisk to wyjsc
    /// @return czy najezdza na przycisk
    bool getQuit(sf::Vector2i mousePos) const
    {
        sf::Vector2f localCords = (sf::Vector2f)mousePos - getPosition();
        return getButtonBounds(quit.getGlobalBounds()).contains(localCords);
    }

    bool getRestart(sf::Vector2i mousePos) const
    {
        sf::Vector2f localCords = (sf::Vector2f)mousePos - getPosition();
        return getButtonBounds(restart.getGlobalBounds()).contains(localCords);
    }

    bool getContinue(sf::Vector2i mousePos) const
    {
        sf::Vector2f localCords = (sf::Vector2f)mousePos - getPosition();
        return getButtonBounds(cont.getGlobalBounds()).contains(localCords);
    }
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        target.draw(background,states);
        target.draw(quit,states);
        target.draw(restart,states);
        target.draw(cont,states);
    }

    /// @brief zwraca pozycje i rozmiar przycisku uwzledniajaca skale
    /// @param bounds uzyj funkcji getGlobalBounds przycisku
    /// @return kwadrat po transformacji
    sf::FloatRect getButtonBounds(sf::FloatRect bounds) const
    {
        sf::FloatRect rect{{bounds.position.x * getScale().x, bounds.position.y * getScale().y}, {bounds.size.x * getScale().x, bounds.size.y * getScale().y}};
        return rect;
    }
};