#include "rocketLauncher.hpp"

namespace
{
    constexpr float range = 700.f;
    constexpr int damage = 15;
}

RocketLauncher::RocketLauncher()
    : Turret(util::AssetLoader::get().rocketLauncher, ::range, ::damage)
{
    cooldown = 100;
}

void RocketLauncher::update()
{
    for(auto& rocket : rockets)
        rocket.update();
}

void RocketLauncher::shoot(sf::Vector2f from, Enemy *target)
{
    cooldown--;
    if(cooldown > 0)
        return; // cooldown nie minal
    cooldown = maxCooldown;
    

    Rocket rocket{target, damage};
    rocket.launch(from, target->getPosition());
    rockets.push_back(rocket);
}