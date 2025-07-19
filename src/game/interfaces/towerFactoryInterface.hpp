#pragma once
#include "../gameObjects/towers/tower.hpp"

/// @brief odpowiada za tworzenie wiez
class ITowerFactory
{
public:
    virtual ~ITowerFactory() = default;

    /// @brief tworzy wieze
    /// @param eManager manager ktory pozwala wiezy widziec przeciwnikow.
    /// Kiedy wyslesz nullptr to wieza bedzie dzialac ale bedzie 'slepa'
    /// @return odowiednia wieza do wybranej fabryki
    virtual std::unique_ptr<Tower> create(IClientEnemyManager* eManager = nullptr) = 0;
};
