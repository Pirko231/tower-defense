#include "levels.hpp"
#include <iostream>

Levels::Levels(const std::filesystem::path &filePath)
{
    using namespace tinyxml2;
    XMLDocument doc;
    XMLError result = doc.LoadFile(filePath.c_str());
    if (result != XML_SUCCESS) {
        std::cerr << "Nie udało się wczytać pliku XML! Kod błędu: " << result << std::endl;
        return;
    }
    XMLElement * levels = doc.FirstChildElement("levels");
    
    for (XMLElement* level = levels->FirstChildElement("level"); level != nullptr; level = level->NextSiblingElement("level"))
    {
        const char* number = level->Attribute("number");

        int price = level->FirstChildElement("price")->IntText();
        int damage = level->FirstChildElement("damage")->IntText();
        float range = level->FirstChildElement("range")->FloatText();

        //std::cout << "Poziom " << number << ": cena=" << price << ", obrazenia=" << damage << ", zasieg=" << range << std::endl;
        levelStats.push_back({price,damage,range});
    }
}