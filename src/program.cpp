#include "program.hpp"

#include "assetloader.hpp"

Program::Program()
    : window(new sf::RenderWindow(sf::VideoMode{{1280, 832}, 32}, "Tower-defense", sf::Style::Titlebar | sf::Style::Close)),
    screenStateMachine(pressed, window)
{
    window->setFramerateLimit(60);
}

void Program::handleEvents()
{
    for (auto& key : pressed.getKeys())
        key.second.released = false;
    for (auto& mouse : pressed.getMouseButtons())
        mouse.second.released = false;

    while (const std::optional ev = window->pollEvent())
    {
        if (ev->is<sf::Event::Closed>())
            window->close();

        if (const auto* keyP = ev->getIf<sf::Event::KeyPressed>())
            pressed[keyP->code].pressed = true;
        if (const auto* keyR = ev->getIf<sf::Event::KeyReleased>())
        {
            pressed[keyR->code].pressed = false;
            pressed[keyR->code].released = true;
        }
        if (const auto* mButtonP = ev->getIf<sf::Event::MouseButtonPressed>())
            pressed[mButtonP->button].pressed = true;
        if (const auto* mButtonR = ev->getIf<sf::Event::MouseButtonReleased>())
        {
            pressed[mButtonR->button].pressed = false;
            pressed[mButtonR->button].released = true;
        }
    }
}

void Program::update()
{
    screenStateMachine.update();
}

void Program::display()
{
    window->clear();

    //strefa rysowania
    window->draw(screenStateMachine);

    window->display();
}
