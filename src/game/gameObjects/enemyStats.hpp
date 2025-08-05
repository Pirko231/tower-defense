#pragma once
#include <filesystem>
#include <unordered_map>

class EnemyStats
{
public:
    struct Stats
    {
        int health{};
        int damage{};
        int money{};
        int shield{};
        float speed{};
    };
private:
    std::unordered_map<int, Stats> enemies;
public:
    EnemyStats(const std::filesystem::path& path);

    Stats operator[](int value) const {return enemies.at(value);}
};