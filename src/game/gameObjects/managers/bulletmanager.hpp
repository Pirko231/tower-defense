#pragma once
#include "../bullets/basicBullet.hpp"
#include "../bullets/rocket.hpp"

class BulletManager : public sf::Drawable
{
public:
    BulletManager();

    void update();

    
};