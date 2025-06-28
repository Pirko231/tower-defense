#ifndef ARCHER_HPP
#define ARCHER_HPP
#include <SFML/Graphics.hpp>


class Archer : public sf::Drawable, public sf::Transformable
{
    const sf::Texture& texture;
    sf::Sprite sprite;
public:
    explicit Archer(const sf::Texture& _texture)
        : texture(_texture), sprite(texture)
    {

    }
    ~Archer();

    void shoot();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();

        target.draw(sprite, states);
    }
};



#endif //ARCHER_HPP
