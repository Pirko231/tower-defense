#pragma once
#include "pauseMenu.hpp"

class EndMenu : public PauseMenu
{
    sf::Text gameOverText;
public:
    EndMenu();

    /// @brief ustawia stan - czy wygrana czy przegrana
    /// @param _state true jesli wygrana, false jesli przegrana
    void setState(bool _state)
    {
        if(_state)
            gameOverText.setString("Victory");
        else
            gameOverText.setString("Defeat");
        gameOverText.setPosition({background.getGlobalBounds().size.x / 2.f - gameOverText.getGlobalBounds().size.x / 2.f, background.getGlobalBounds().size.y / 5.f});
    }

    bool getContinue(sf::Vector2i mousePos) const override {throw std::runtime_error("EndMenu::getContinue() is unsupported");}

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        drawDefaultButtons(target,states);
        drawStats(target,states);
        target.draw(gameOverText,states);
    }
};