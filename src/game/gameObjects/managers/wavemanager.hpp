#pragma once
#include "enemymanager.hpp"
#include <filesystem>
#include <fstream>

#include "../factories/basicSoldierFactory.hpp"
#include "../factories/eliteSoldierFactory.hpp"
#include "../factories/mechaSoldierFactory.hpp"
#include "../factories/superSoldierFactory.hpp"

// na razie zdefiniuje tutaj potem sie przerzuci w razie potrzeby
enum class EnemyType
{
    Empty = 0, // tylko dla error handling
    BasicSoldier = 1,
    EliteSoldier = 2,
    MechaSoldier = 3,
    SuperSoldier = 4
};

/// @brief tworzy przeciwnikow i wysyla informacje do enemyManager
class WaveManager
{
    Map* map{};
    EnemyManager* enemyManager{};
    
    std::vector<std::vector<EnemyType>> enemies;
    std::vector<std::vector<EnemyType>>::iterator currentWave{};
    
    bool firstWave{}; // gra pauzuje przed pierwsza fala
    int maxWaves{};
    int waves{};
public:
    WaveManager(Map* _map, EnemyManager* _enemyManager);

    /// @brief wczytuje przeciwnikow z pliku
    /// @param filePath sciezka do pliku
    void loadEnemies(const std::filesystem::path& filePath);

    void update();

    /// @brief sprawdza czy obecnie trwa jakas fala
    bool isWaveActive() const
    {
        if(firstWave)
            return false;

        return currentWave != enemies.end() || currentWave->size() != 0;
    }

    /// @brief ustawia kolejna fale
    void nextWave()
    {
        if(waves >= maxWaves)
            return;
        currentWave = enemies.begin(); waves++;
        firstWave = false;
    }

    int getMaxWaves() const {return maxWaves;}

    int getWaves() const {return waves;}
private:
    /// @brief przerabia tekst na EnemyType
    /// @param line tekst do przerobienia
    EnemyType loadEnemy(const std::string& line);

    /// @brief interpretuje typ i zwraca odpowiednia fabryke. Kiedy typ nie zostanie rozpoznany
    /// zwraca BasicSoldierfactory
    /// @param type typ do interpretacji
    /// @return fabryka
    std::unique_ptr<IEnemyFactory> getFactory(EnemyType type);
};