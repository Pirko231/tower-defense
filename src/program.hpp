#pragma once
#include <SFML/Graphics.hpp>

#include "screens/screenstatemachine.hpp"
#include "pressed.hpp"

class Program
{
    sf::RenderWindow* window;
    Pressed pressed;

    ScreenStateMachine screenStateMachine;
public:
    Program();

    ~Program()
    {
        delete window;
    }
    [[nodiscard]] bool running() const {return window->isOpen();}
    void handleEvents();
    void update();
    void display();
};
