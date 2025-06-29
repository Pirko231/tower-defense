#pragma once

#include <map>
#include <SFML/Graphics.hpp>

struct keyBind
{
    bool pressed{};
    bool released{};
};

class Pressed
{
    std::map<sf::Keyboard::Key, keyBind> keys;
    std::map<sf::Mouse::Button, keyBind> mouseButtons;
public:
    Pressed() = default;

    keyBind& operator[](sf::Keyboard::Key key) {return keys[key];}
    keyBind& operator[](sf::Mouse::Button button) {return mouseButtons[button];}

    keyBind& at(sf::Keyboard::Key key) {return keys.at(key);}
    keyBind& at(sf::Mouse::Button button) {return mouseButtons.at(button);}

    void clearKeys() {keys.clear();}
    void clearMouse() {mouseButtons.clear();}

    std::map<sf::Keyboard::Key, keyBind>& getKeys() {return keys;}
    std::map<sf::Mouse::Button, keyBind>& getMouseButtons() {return mouseButtons;}
};
