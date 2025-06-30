#pragma once
#include <SFML/Graphics.hpp>

class ScreenState : public sf::Drawable
{

public:
    virtual void update() = 0;
};
