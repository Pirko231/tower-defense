#include "rocketLauncher.hpp"

namespace
{
    constexpr float range = 700.f;
    constexpr int damage = 150;
}

RocketLauncher::RocketLauncher()
    : Turret(util::AssetLoader::get().rocketLauncher, ::range, ::damage)
{
    maxCooldown = 400;
}

void RocketLauncher::update()
{
    std::erase_if(rockets, [](const Rocket& b)->bool{return b.shouldDelete();});
    for(auto& rocket : rockets)
    {
        rocket.update();
        rocket.hitTarget();
    }
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