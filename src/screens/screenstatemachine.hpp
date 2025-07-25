#pragma once
#include "states/mainmenuscreen.hpp"
#include "states/gamescreen.hpp"
#include "screenstatemachineinterface.hpp"
#include "states/mapselectionscreen.hpp"

class ScreenStateMachine : public sf::Drawable, public IScreenStateMachine
{
    std::unique_ptr<ScreenState> mainMenuScreen;
    std::unique_ptr<ScreenState> gameScreen;
    std::unique_ptr<ScreenState> mapSelectionScreen;
    ScreenState* currentState{};
public:
    ScreenStateMachine(Pressed& pressed, sf::RenderWindow* _window);

    void update();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setCurrentMap(const std::filesystem::path& _mapPath, int decorAmount) override
    {
        static_cast<GameScreen*>(gameScreen.get())->setCurrentMap(_mapPath,decorAmount);
    }

    void setCurrentEnemies(const std::filesystem::path& _enemyPath) override
    {
        static_cast<GameScreen*>(gameScreen.get())->setCurrentEnemies(_enemyPath);
    }

    void setState(ScreenState* newState) override {currentState = newState;}
    ScreenState* getMainMenuScreen() override {return mainMenuScreen.get();}
    ScreenState* getGameScreen() override {return gameScreen.get();}
    ScreenState* getMapSelectionScreen() override {return mapSelectionScreen.get();}
};
