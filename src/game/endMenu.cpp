#include "endMenu.hpp"

EndMenu::EndMenu()
    : gameOverText(util::AssetLoader::get().font)
{
    quit.setPosition({background.getGlobalBounds().size.x / 3.f - quit.getGlobalBounds().size.x / 2.f, background.getGlobalBounds().size.y - quit.getGlobalBounds().size.y / 1.5f});
    restart.setPosition({quit.getPosition().x + quit.getGlobalBounds().size.x * 1.5f, restart.getPosition().y});

    gameOverText.setString("test"); gameOverText.setCharacterSize(80u);
    gameOverText.setPosition({background.getGlobalBounds().size.x / 2.f - gameOverText.getGlobalBounds().size.x / 2.f, background.getGlobalBounds().size.y / 5.f});
}