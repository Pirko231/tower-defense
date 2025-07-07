#pragma once
#include "../map.hpp"

// checkpoint nie ma byc drawable, to jest tylko test
class Checkpoint : public sf::Drawable, public sf::Transformable
{
    sf::FloatRect bounds{{0.f,0.f}, static_cast<sf::Vector2f>(util::tileSize)};
public:
    Checkpoint() = default;
    Checkpoint(sf::Vector2f position)
        : bounds(position, static_cast<sf::Vector2f>(util::tileSize))
    {}

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        sf::RectangleShape shape(bounds.size);

        target.draw(shape, states);
    }
};

class EnemyManager : public sf::Drawable
{
    struct Direction
    {
        bool up{},down{},left{},right{};
        bool operator!=(const Direction& direction) const {return direction.up != up || direction.down != down || direction.left != left || direction.right != right;}
    };

    Map* map{};

    std::vector<Checkpoint> checkpoints;
public:
    EnemyManager(Map* _map);

    void update();

    void loadCheckPoints();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    Direction checkDirection(const Tile& first, const Tile& second);
};

