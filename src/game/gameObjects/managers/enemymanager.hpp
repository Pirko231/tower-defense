#pragma once
#include "../map.hpp"

class EnemyManager : public sf::Drawable
{
    Map* map{};
public:
    EnemyManager(Map* _map);

    void update();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

