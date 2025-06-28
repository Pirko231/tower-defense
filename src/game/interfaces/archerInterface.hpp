//
// Created by szymek on 27.06.25.
//

#ifndef IARCHER_HPP
#define IARCHER_HPP

#include  <SFML/Graphics.hpp>

class IArcher : public sf::Transformable, public sf::Drawable
{
public:
    virtual void shoot() = 0;
};



#endif //IARCHER_HPP
