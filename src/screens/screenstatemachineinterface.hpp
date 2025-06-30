#pragma once
#include "states/screenstate.hpp"

class ScreenState;

class IScreenStateMachine
{
public:
    virtual ScreenState* getMainMenuScreen() = 0;

    virtual ScreenState* getGameScreen() = 0;

    virtual void setState(ScreenState*) = 0;
};
