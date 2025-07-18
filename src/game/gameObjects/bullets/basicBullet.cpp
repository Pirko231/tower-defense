#include "basicBullet.hpp"

BasicBullet::BasicBullet(float _speed)
    : sprite(util::AssetLoader::get().basicBullet),
    speed(_speed), timerMax{480}, timer{timerMax}
{
}

void BasicBullet::update()
{
    move(moveBy);

    timer--;
    hitTimer--;
}

void BasicBullet::launch(sf::Vector2f from, sf::Vector2f where)
{
    // wektor ruchu
    moveBy = where - from;
    hitTimer = (int)moveBy.length();
    if(moveBy != sf::Vector2f{})
        moveBy = moveBy.normalized();
}
