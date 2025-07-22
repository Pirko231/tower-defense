#pragma once
#include "turret.hpp"
#include "../bullets/rocket.hpp"

class RocketLauncher : public Turret
{
    std::vector<Rocket> rockets;
public:
    RocketLauncher();
    void update() override;
    void shoot(sf::Vector2f, Enemy*) override;
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        Turret::draw(target,states);
        states.transform *= getTransform();
        for(auto& rocket : rockets)
            target.draw(rocket);
    }
};