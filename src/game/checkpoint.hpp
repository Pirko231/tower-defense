#pragma once
#include <SFML/Graphics.hpp>
#include "base.hpp"

// checkpoint nie ma byc drawable, to jest tylko test
class Checkpoint : public sf::Transformable
{
    sf::FloatRect bounds{{0.f,0.f}, static_cast<sf::Vector2f>(util::tileSize)};
public:
    Checkpoint() = default;
    Checkpoint(sf::Vector2f position)
    {
        setPosition(position);
    }

    sf::FloatRect getGlobalBounds() const {return sf::FloatRect(getPosition(), bounds.size);}

    class Iterator
    {
        std::vector<Checkpoint>& checkpoints;
        std::vector<Checkpoint>::iterator current;
    public:
        Iterator(std::vector<Checkpoint>::iterator _current, std::vector<Checkpoint>& _data)
            : checkpoints(_data), current(_current)
        {}

        Checkpoint& operator*() {return *current;}

        void operator++(int) {current++;}

        Checkpoint* operator->() const {return &(*current);}

        bool hasNext() const {return current != checkpoints.end();}
    };
};