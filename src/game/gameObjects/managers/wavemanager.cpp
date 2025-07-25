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

    // timer do odmierzania czasu do pojawiania sie kolejnych przeciwnikow
    static int timer{0};
    if(timer > 0)
    {
        timer--;
        return;
    }
    timer = currentWave->back().timer;
    
    enemyManager->addEnemy(getFactory(currentWave->back().type).get());
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
            if(std::size_t pos = data.find('\n'); pos != std::string::npos)
            {
                std::string temp = std::string(data.begin(), data.begin() + pos);
                data.erase(data.begin() , data.begin() + pos + 1);
                auto enemy = loadEnemy(temp);
                if(enemy.type != EnemyType::Empty)
                    enemies.back().emplace_back(enemy);

                enemies.push_back({});
                //data = temp; // w tym wypadku ladowane sa dwie wartosci - teraz pracujemy na tej drugiej odzyskanej
            }

            auto enemy = loadEnemy(data);
            if(enemy.type != EnemyType::Empty)
                enemies.back().emplace_back(enemy);
        }

        //enemies.pop_back(); // ostatnia linia bedzie invalid
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

PackedEnemy WaveManager::loadEnemy(std::string &line)
{
    PackedEnemy result{EnemyType::Empty, 0};
    std::string timer = std::string(line.begin() + line.find(',') + 1, line.end());
    line.erase(line.begin() + line.find(','), line.end());
    try
    {
        int val = std::stoi(timer);
        result.timer = val;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Timer loading " << e.what() << '\n';
    }
    
    try
    {
        int val = std::stoi(line);
        result.type = static_cast<EnemyType>(val);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Type loading " << e.what() << '\n';
    }
    
    return result;
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
