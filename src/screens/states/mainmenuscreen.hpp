#pragma once
#include "screenstate.hpp"
#include "../buttons/textbutton.hpp"
#include "../buttons/playbutton.hpp"
#include "base.hpp"
#include "assetloader.hpp"

class MainMenuScreen : public ScreenState
{
    sf::Sprite background;

    btn::PlayButton playButton;
public:
    MainMenuScreen(IScreenStateMachine*);

    void update() override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
