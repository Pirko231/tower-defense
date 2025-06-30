#include "program.hpp"

#include "assetloader.hpp"

Program::Program()
    : towerManager(&map), towerManagerProxy(&towerManager), buildingUI(&map)
{
    window = new sf::RenderWindow(sf::VideoMode{{1280, 832}, 32}, "Tower-defense", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(60);

    towerManagerProxy.addTower({19,11}, TowerType::Archer);
    towerManagerProxy.addTower({12,11}, TowerType::Archer);
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
            pressed[mButtonR->button].pressed = true;
            pressed[mButtonR->button].released = true;
        }
    }
}

void Program::update()
{
    util::AssetLoader::get();

    towerManager.update();

    if (pressed[sf::Mouse::Button::Left].released)
        buildingUI.click(sf::Mouse::getPosition(*window));
}

void Program::display()
{
    window->clear();

    //strefa rysowania
    map.display(window);

    towerManager.display(window);

    window->draw(buildingUI);

    window->display();
}
