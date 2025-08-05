#pragma once
#include "tinyxml2.hpp"
#include <filesystem>
#include <iostream>
#include <unordered_map>

class MapInfo
{
public:
    struct MapData
    {
        std::filesystem::path mapPath;
        std::filesystem::path enemyPath;
        std::string name;
        int decorAmount;
        int health;
        int money;
    };
private:
    std::unordered_map<int, MapData> data;
public:
    

    MapInfo(const std::filesystem::path& path)
    {
        tinyxml2::XMLDocument doc;
        auto result = doc.LoadFile(path.c_str());
        if(result != tinyxml2::XML_SUCCESS)
        {
            std::cerr << "XML file failed to open " << path << '\n';
            return;
        }

        tinyxml2::XMLElement* maps = doc.FirstChildElement("maps");
        for(tinyxml2::XMLElement* map = maps->FirstChildElement("map"); map != nullptr; map = map->NextSiblingElement("map"))
        {
            int number = map->IntAttribute("number");
            std::filesystem::path mapPath = map->FirstChildElement("mapPath")->GetText();
            std::filesystem::path enemyPath = map->FirstChildElement("enemyPath")->GetText();
            std::string name = map->FirstChildElement("name")->GetText();
            int decorAmount = map->FirstChildElement("decorAmount")->IntText();
            int health = map->FirstChildElement("health")->IntText();
            int money = map->FirstChildElement("money")->IntText();
            data[number] = MapData{std::move(mapPath), std::move(enemyPath), std::move(name), decorAmount, health, money};
        }
    }

    MapData operator[](int key) {return data.at(key);}
};