#pragma once
#include "../gameObjects/towers/tower.hpp"
#include "bulletManagerInterface.hpp"

/// @brief odpowiada za tworzenie wiez
class ITowerFactory
{
public:
    virtual ~ITowerFactory() = default;

    /// @brief tworzy wieze
    /// @param eManager manager ktory pozwala wiezy widziec przeciwnikow.
    /// Kiedy wyslesz nullptr to wieza bedzie dzialac ale bedzie 'slepa'
    /// @param bManager manager ktory pozwala wiezy strzelac
    /// mozna wyslac nullptr
    /// @return odowiednia wieza do wybranej fabryki
    virtual std::unique_ptr<Tower> create(IClientEnemyManager* eManager = nullptr, IBulletManager* bManager = nullptr) = 0;
};
