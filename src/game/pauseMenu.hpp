#pragma once
#include "SFML/Graphics.hpp"
#include "base.hpp"

class PauseMenu : public sf::Drawable, public sf::Transformable
{
protected:
    sf::Sprite background;

    sf::Sprite quit;
    sf::Sprite restart;
    sf::Sprite cont; // continue

    sf::Sprite coinIcon;
    sf::Text coinText;

    sf::Sprite healthIcon;
    sf::Text healthText;
public:
    PauseMenu();

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect{getPosition(),{background.getGlobalBounds().size.x * getScale().x, background.getGlobalBounds().size.y * getScale().y}};}

    /// @brief zwraca czy powinno sie wyjsc do ekranu glownego
    /// @param mousePos pozycja myszki - kiedy najezdza na przycisk to wyjsc
    /// @return czy najezdza na przycisk
    virtual bool getQuit(sf::Vector2i mousePos) const
    {
        sf::Vector2f localCords = (sf::Vector2f)mousePos - getPosition();
        return getButtonBounds(quit.getGlobalBounds()).contains(localCords);
    }

    virtual bool getRestart(sf::Vector2i mousePos) const
    {
        sf::Vector2f localCords = (sf::Vector2f)mousePos - getPosition();
        return getButtonBounds(restart.getGlobalBounds()).contains(localCords);
    }

    virtual bool getContinue(sf::Vector2i mousePos) const
    {
        sf::Vector2f localCords = (sf::Vector2f)mousePos - getPosition();
        return getButtonBounds(cont.getGlobalBounds()).contains(localCords);
    }

    void setStats(int health, int money) {healthText.setString(std::to_string(health)); coinText.setString(std::to_string(money));}
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        drawDefaultButtons(target,states);
        drawStats(target,states);
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
protected:
    void drawDefaultButtons(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(background,states);
        target.draw(quit,states);
        target.draw(restart,states);
    }

    void drawStats(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(coinIcon,states);
        target.draw(coinText,states);
        target.draw(healthIcon,states);
        target.draw(healthText,states);
    }
};