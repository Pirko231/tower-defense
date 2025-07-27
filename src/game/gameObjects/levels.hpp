#pragma once
#include <filesystem>
#include <vector>
#include "tinyxml2.hpp"

struct Stats
{
    int price{};
    int damage{};
    float range{};
};

class Levels
{
    std::vector<Stats> levelStats;
    int currentLevel{};
public:
    Levels(const std::filesystem::path& filePath);

    int getCurrentLevel() const {return currentLevel;}

    Stats getCurrentStats() const {return levelStats[currentLevel];}
}; 