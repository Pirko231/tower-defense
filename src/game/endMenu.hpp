#pragma once
#include "pauseMenu.hpp"

class EndMenu : public PauseMenu
{
    bool state;
public:
    EndMenu();

    /// @brief ustawia stan - czy wygrana czy przegrana
    /// @param _state true jesli wygrana, false jesli przegrana
    void setState(bool _state) {state = _state;}

    bool getContinue(sf::Vector2i mousePos) const override {throw std::runtime_error("EndMenu::getContinue() is unsupported");}

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        target.draw(background,states);
        target.draw(quit,states);
        target.draw(restart,states);
    }
};