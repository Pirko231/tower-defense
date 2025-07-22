#pragma once
#include "bullet.hpp"
#include "../enemies/enemy.hpp"
#include "base.hpp"

class BasicBullet : public Bullet
{
    int hitTimer{};
public:
    BasicBullet(Enemy* _target, int _damage);

    void update() override;

    void launch(sf::Vector2f from, sf::Vector2f where) override;

    bool hasHitTarget() const override {return hitTimer <= 0;}

    /// @brief sprawdza czy trafil w cel, jesli tak to wykonuje cala prace (zadanie obraze)
    /// potem oznacza sie jako pocisk do usuniecia
    void hitTarget() override;
private:
};