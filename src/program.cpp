#include "program.hpp"

#include "assetloader.hpp"

Program::Program()
{
    window = new sf::RenderWindow(sf::VideoMode{{1280u,720u}, 32}, "Tower-defense", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(60);

    towerManager.addTower({20,12}, TowerType::Archer);
}

void Program::handleEvents()
{
    while (const std::optional ev = window->pollEvent())
    {
        if (ev->is<sf::Event::Closed>())
            window->close();
    }
}

void Program::update()
{
    util::AssetLoader::get();

    towerManager.update();
}

void Program::display()
{
    window->clear();

    //strefa rysowania
    towerManager.display(window);

    window->display();
}
