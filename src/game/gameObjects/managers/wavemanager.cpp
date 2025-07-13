#include "wavemanager.hpp"

WaveManager::WaveManager(Map *_map, EnemyManager *_enemyManager)
    : map(_map), enemyManager(_enemyManager)
{}

void WaveManager::update()
{
    if(enemies.size() == 0)
        return;

    // prymitywny timer potem wywalic
    static int timer{1};
    if(timer % 120 != 0)
    {
        timer++;
        return;
    }
    timer = 1;
    
    enemyManager->addEnemy(getFactory(enemies.back()).get());
    enemies.pop_back();
}

void WaveManager::loadEnemies(const std::filesystem::path &filePath)
{
    enemies.clear();

    std::fstream file;
    file.open(filePath, std::ios::in);
    if(file.is_open())
    {
        std::string data;
        
        while(!file.eof())
        {
            std::getline(file, data, ' ');
            auto enemy = loadEnemy(data);
            if(enemy != EnemyType::Empty)
                enemies.emplace_back(enemy);
        }
    }
    else
        std::cerr << "File could not open " << filePath << '\n';
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

    return nullptr;
}
