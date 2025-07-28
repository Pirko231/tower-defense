#pragma once
#include <filesystem>
#include <vector>

struct Stats
{
    int price{};
    int damage{};
    float range{};
    int maxFireSpeed{};
};

class Levels
{
    std::vector<Stats> levelStats;
    int currentLevel{};
public:
    Levels(const std::filesystem::path& filePath);

    int getCurrentLevel() const {return currentLevel;}

    int getMaxLevel() const {return levelStats.size() - 1;}

    Stats getCurrentStats() const {return levelStats[currentLevel];}

    Stats getNextStats() const {return levelStats[currentLevel + 1];}

    void nextLevel() {currentLevel++;}
}; 