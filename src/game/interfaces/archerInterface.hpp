//
// Created by szymek on 27.06.25.
//

#ifndef IARCHER_HPP
#define IARCHER_HPP

#include  <SFML/Graphics.hpp>

class IArcher : public sf::Transformable, public sf::Drawable
{
public:
    virtual void shoot(sf::Vector2f where) = 0;

    virtual void setRange(float) = 0;

    virtual sf::FloatRect getGlobalBounds() const = 0;
};



#endif //IARCHER_HPP
