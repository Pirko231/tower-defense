#pragma once
#include "bulletInterface.hpp"
#include "../enemies/enemy.hpp"
#include "base.hpp"

class Rocket : public IBullet
{
    sf::Sprite sprite;
    sf::Vector2f moveBy;
    float speed{};
    Enemy* target{};

    int damage;
    bool shouldDelete_{};
public:
    Rocket(Enemy* _target, int _damage);

    void update() override;

    void launch(sf::Vector2f from, sf::Vector2f where) override;

    sf::FloatRect getGlobalBounds() const override {return sf::FloatRect{getPosition(), sprite.getGlobalBounds().size};}

    Enemy* getTarget() const override {return target;}

    int getDamage() const override {return damage;}

    bool shouldDelete() const override {return shouldDelete_;}

    /// @brief sprawdza czy trafil w cel, jesli tak to wykonuje cala prace (zadanie obraze)
    /// potem oznacza sie jako pocisk do usuniecia
    void hitTarget() override;
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        target.draw(sprite, states);
    }
};