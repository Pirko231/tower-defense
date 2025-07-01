#pragma once
#include "screenstate.hpp"

class MapSelectionScreen : public ScreenState
{
public:
    MapSelectionScreen(IScreenStateMachine* _stateMachine);

    virtual void update() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
