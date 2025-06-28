#include "map.hpp"

#include "base.hpp"

Map::Map()
{
    loadMap("map1.txt");
}

void Map::loadMap(const std::filesystem::path& path)
{
    std::fstream file(path, std::ios::in);

    sf::Vector2i mapPos = sf::Vector2i(0, 0);
    while (!file.eof())
    {
        std::string line;
        int value{};
        std::getline(file, line, ' ');
        mapPos.x++;
        if (line.find('\n') != std::string::npos)
        {
            mapPos.y++;
            mapPos.x = 0;
        }
        if (line.empty())
            break;
        try
        {
            value = std::stoi(line);
            Tile tile = createTile(static_cast<TileType>(value));
            tile.setPosition(util::calculatePosition(mapPos));
            tiles.push_back(tile);
        }
        catch (std::exception& e)
        {
            std::cerr << "error at map loading: " << e.what() << std::endl;
        }
    }
}

Tile Map::createTile(TileType type)
{
    if (type == TileType::Grass)
        return Tile{util::AssetLoader::get().grassTile};

    return Tile{util::AssetLoader::get().emptyTexture};
}
