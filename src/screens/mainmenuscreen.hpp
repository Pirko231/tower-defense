#pragma once
#include "screenstate.hpp"

class MainMenuScreen : public ScreenState
{
public:
    MainMenuScreen() = default;

    void update() override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
