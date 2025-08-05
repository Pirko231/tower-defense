#include "pauseMenu.hpp"

PauseMenu::PauseMenu()
    : background(util::AssetLoader::get().pauseMenuBackground), quit(util::AssetLoader::get().quitButton),
    restart(util::AssetLoader::get().restartButton), cont(util::AssetLoader::get().continueButton),
    coinIcon(util::AssetLoader::get().coinIcon), coinText(util::AssetLoader::get().font),
    healthIcon(util::AssetLoader::get().healthIcon), healthText(util::AssetLoader::get().font)
{
    quit.setPosition({background.getGlobalBounds().size.x / 3.1f - quit.getGlobalBounds().size.x,background.getGlobalBounds().size.y - quit.getGlobalBounds().size.y / 1.5f});
    restart.setPosition({background.getGlobalBounds().size.x / 1.7f - restart.getGlobalBounds().size.x,background.getGlobalBounds().size.y - restart.getGlobalBounds().size.y / 1.5f});
    cont.setPosition({background.getGlobalBounds().size.x / 1.15f - cont.getGlobalBounds().size.x, background.getGlobalBounds().size.y - cont.getGlobalBounds().size.y / 1.5f});

    healthIcon.setScale({3.f,3.f});
    healthIcon.setPosition({background.getGlobalBounds().size.x / 3.f - healthIcon.getGlobalBounds().size.x, background.getGlobalBounds().size.y / 3.f + healthIcon.getGlobalBounds().size.y});
    healthText.setString("test"); healthText.setCharacterSize(60u);
    healthText.setPosition({healthIcon.getPosition().x + healthIcon.getGlobalBounds().size.x * 1.2f, healthIcon.getPosition().y});

    coinIcon.setScale({3.f,3.f});
    coinIcon.setPosition({healthIcon.getPosition().x - 60.f, healthIcon.getPosition().y + healthIcon.getGlobalBounds().size.y * 1.f});
    coinText.setString("test"); coinText.setCharacterSize(60u);
    coinText.setPosition({coinIcon.getPosition().x + coinIcon.getGlobalBounds().size.x * 1.f - 20.f, coinIcon.getPosition().y + 50.f});
}