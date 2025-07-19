#include "wavemanager.hpp"

WaveManager::WaveManager(Map *_map, EnemyManager *_enemyManager)
    : map(_map), enemyManager(_enemyManager)
{}

void WaveManager::update()
{
    if(firstWave)
        return;

    if(currentWave->size() == 0 || currentWave == enemies.end())
        return;

    // prymitywny timer potem wywalic
    static int timer{1};
    if(timer % 120 != 0)
    {
        timer++;
        return;
    }
    timer = 1;
    
    enemyManager->addEnemy(getFactory(currentWave->back()).get());
    currentWave->pop_back();
    if(currentWave->size() == 0)
    {
        enemies.erase(enemies.begin());
        currentWave = enemies.end();
    }
    //currentWave = enemies.begin();
}

void WaveManager::loadEnemies(const std::filesystem::path &filePath)
{
    enemies.clear();
    firstWave = true;

    std::fstream file;
    file.open(filePath, std::ios::in);
    if(file.is_open())
    {
        std::string data;
        enemies.push_back({}); // pierwsza fala
        
        while(!file.eof())
        {
            std::getline(file, data, ' ');

            // szukanie znaku nowej lini
            if(data.find('\n') != std::string::npos)
            {
                std::string temp = std::to_string(static_cast<char>(data.back()) - 48);
                data.erase(data.begin() + 1, data.end());
                auto enemy = loadEnemy(data);
                if(enemy != EnemyType::Empty)
                    enemies.back().emplace_back(enemy);

                enemies.push_back({});
                data = temp; // w tym wypadku ladowane sa dwie wartosci - teraz pracujemy na tej drugiej odzyskanej
            }

            auto enemy = loadEnemy(data);
            if(enemy != EnemyType::Empty)
                enemies.back().emplace_back(enemy);
        }

        enemies.pop_back(); // ostatnia linia bedzie invalid
        currentWave = enemies.begin();
    }
    else
    {
        std::cerr << "File could not open " << filePath << '\n';
        loadEnemies("resources/maps/defaultEnemies.txt");
    }


    maxWaves = enemies.size();
    waves = 0;
}

EnemyType WaveManager::loadEnemy(const std::string &line)
{
    try
    {
        int val = std::stoi(line);
        return static_cast<EnemyType>(val);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return EnemyType::Empty;
}

std::unique_ptr<IEnemyFactory> WaveManager::getFactory(EnemyType type)
{
    if(type == EnemyType::BasicSoldier)
        return std::make_unique<BasicSoldierFactory>();
    else if(type == EnemyType::EliteSoldier)
        return std::make_unique<EliteSoldierFactory>();
    else if(type == EnemyType::MechaSoldier)
        return std::make_unique<MechaSoldierFactory>();
    else if(type == EnemyType::SuperSoldier)
        return std::make_unique<SuperSoldierFactory>();

    return std::make_unique<BasicSoldierFactory>();
}
