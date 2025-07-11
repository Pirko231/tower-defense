#include "healthbar.hpp"

HealthBar::HealthBar(int _maxHealth)
    : maxHealth(_maxHealth)
{
    background.setSize({30.f, 6.f});
    background.setFillColor(sf::Color::Red);
    
    current.setFillColor(sf::Color::Green);
}

void HealthBar::update(int health)
{
    float healthPercent = (float)health / (float)maxHealth;
    if(healthPercent < 0)
        return;

    current.setSize({background.getSize().x * healthPercent, 6.f});
}
