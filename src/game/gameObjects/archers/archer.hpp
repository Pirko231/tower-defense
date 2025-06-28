#ifndef ARCHER_HPP
#define ARCHER_HPP
#include "archerInterface.hpp"


class Archer : public IArcher
{
    sf::Sprite sprite;
public:
    explicit Archer(const sf::Texture& _texture)
        : sprite(_texture)
    {

    }
    Archer(const Archer& archer)
        : sprite(archer.sprite)
    {}
    Archer(Archer&&) = default;
    ~Archer() override = default;

    void shoot() override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        target.draw(sprite, states);
    }
};



#endif //ARCHER_HPP
