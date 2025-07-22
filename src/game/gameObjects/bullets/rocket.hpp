#pragma once
#include "bullet.hpp"
#include "../enemies/enemy.hpp"
#include "base.hpp"

class Rocket : public Bullet
{
public:
    Rocket(Enemy* _target, int _damage);

    void update() override;

    void launch(sf::Vector2f from, sf::Vector2f where) override;

    bool hasHitTarget() const {return false;}

    /// @brief sprawdza czy trafil w cel, jesli tak to wykonuje cala prace (zadanie obraze)
    /// potem oznacza sie jako pocisk do usuniecia
    void hitTarget() override;
};