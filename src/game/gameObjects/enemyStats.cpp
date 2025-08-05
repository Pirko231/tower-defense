#include "enemyStats.hpp"
#include "tinyxml2.hpp"
#include <iostream>

EnemyStats::EnemyStats(const std::filesystem::path& path)
{
    using namespace tinyxml2;
    XMLDocument doc;
    XMLError result = doc.LoadFile(path.c_str());
    if (result != XML_SUCCESS) {
        std::cerr << "Nie udało się wczytać pliku XML! Kod błędu: " << result << std::endl;
        return;
    }
    XMLElement* enemies = doc.FirstChildElement("enemies");

    for(XMLElement* enemy = enemies->FirstChildElement("enemy"); enemy != nullptr; enemy = enemy->NextSiblingElement("enemy"))
    {
        int type = std::stoi(enemy->Attribute("type"));

        int health = enemy->FirstChildElement("health")->IntText();
        int damage = enemy->FirstChildElement("damage")->IntText();
        int money = enemy->FirstChildElement("money")->IntText();
        int shield = enemy->FirstChildElement("shield")->IntText();
        float speed = enemy->FirstChildElement("speed")->FloatText();
        this->enemies[type] = Stats{health,damage,money,shield,speed};
    }
}