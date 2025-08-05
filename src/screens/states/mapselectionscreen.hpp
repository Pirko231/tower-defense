#pragma once
#include "screenstate.hpp"
#include "../buttons/mapbutton.hpp"
#include "mapInfo.hpp"

class MapSelectionScreen : public ScreenState
{
    sf::Sprite background;
    sf::Text title;
    MapInfo buttonInfo;
    std::array<btn::MapButton, 6> mapButtons;
public:
    MapSelectionScreen(IScreenStateMachine* _stateMachine);

    virtual void update() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};