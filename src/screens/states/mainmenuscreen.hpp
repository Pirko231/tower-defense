#pragma once
#include "screenstate.hpp"
#include "../buttons/textbutton.hpp"
#include "base.hpp"
#include "assetloader.hpp"

class MainMenuScreen : public ScreenState
{
    Pressed& pressed;
    sf::RenderWindow* window{};

    btn::TextButton playButton;
public:
    MainMenuScreen(IScreenStateMachine*, Pressed& _pressed, sf::RenderWindow* _window);

    void update() override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
