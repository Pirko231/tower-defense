#include "pauseMenu.hpp"

PauseMenu::PauseMenu()
    : background(util::AssetLoader::get().pauseMenuBackground), quit(util::AssetLoader::get().quitButton),
    restart(util::AssetLoader::get().restartButton), cont(util::AssetLoader::get().continueButton)
{
    quit.setPosition({background.getGlobalBounds().size.x / 3.1f - quit.getGlobalBounds().size.x,background.getGlobalBounds().size.y - quit.getGlobalBounds().size.y / 1.5f});
    restart.setPosition({background.getGlobalBounds().size.x / 1.7f - restart.getGlobalBounds().size.x,background.getGlobalBounds().size.y - restart.getGlobalBounds().size.y / 1.5f});
    cont.setPosition({background.getGlobalBounds().size.x / 1.15f - cont.getGlobalBounds().size.x, background.getGlobalBounds().size.y - cont.getGlobalBounds().size.y / 1.5f});
}