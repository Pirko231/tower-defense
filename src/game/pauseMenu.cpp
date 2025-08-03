#include "pauseMenu.hpp"

PauseMenu::PauseMenu()
    : background(util::AssetLoader::get().pauseMenuBackground), quit(util::AssetLoader::get().quitButton)
{
    quit.setPosition({background.getGlobalBounds().size.x / 3.f - quit.getGlobalBounds().size.x,background.getGlobalBounds().size.y - quit.getGlobalBounds().size.y / 1.5f});
}