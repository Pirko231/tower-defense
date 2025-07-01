#include "map.hpp"

#include "base.hpp"

Map::Map(const std::filesystem::path& fileName)
{
    loadMap(fileName);
}

void Map::loadMap(const std::filesystem::path& path)
{
    tiles.clear();
    buildPoints.clear();

    std::fstream file(path, std::ios::in);

    sf::Vector2i mapPos = sf::Vector2i(0, 0);

    if (!file.is_open())
    {
        std::cerr << "File could not open " << path << '\n';
        std::cerr << "Absoulte path: " << absolute(path) << '\n';
    }

    while (!file.eof())
    {
        std::string line;
        int value{};
        std::getline(file, line, ' ');

        if (line.empty())
            break;
        try
        {
            value = std::stoi(line);

            if (static_cast<TileType>(value) == TileType::BuildPoint)
            {
                auto buildPoint = BuildPoint{util::AssetLoader::get().buildPoint};
                buildPoint.setPosition(util::calculatePosition(mapPos));
                buildPoints.push_back(buildPoint);

                value = static_cast<int>(tiles.back().getType());
                auto it = tiles.end() - 1;
                // teraz szukamy ostatniego pola ktore nie jest trasa
                while (static_cast<TileType>(value) == TileType::Road)
                {
                    value = static_cast<int>(it->getType());
                    it--;
                }
            }
            Tile tile = createTile(static_cast<TileType>(value));
            tile.setPosition(util::calculatePosition(mapPos));
            tiles.push_back(tile);
        }
        catch (const std::exception& e)
        {
            std::cerr << "error at map loading: " << e.what() << std::endl;
        }
        mapPos.x++;
        if (line.find('\n') != std::string::npos)
        {
            mapPos.y++;
            mapPos.x = 0;
            line.erase(line.begin(), line.begin() + line.find('\n') + 1);
            if (!line.empty())
                try
                {
                    value = std::stoi(line);

                    if (static_cast<TileType>(value) == TileType::BuildPoint)
                    {
                        auto buildPoint = BuildPoint{util::AssetLoader::get().buildPoint};
                        buildPoint.setPosition(util::calculatePosition(mapPos));
                        buildPoints.push_back(buildPoint);
                        value = static_cast<int>(tiles.back().getType());
                    }
                    Tile tile = createTile(static_cast<TileType>(value));
                    tile.setPosition(util::calculatePosition(mapPos));
                    tiles.push_back(tile);
                    mapPos.x++;
                }
                catch (std::exception& e)
                {
                    std::cerr << "error at map loading(\\n): " << e.what() << std::endl;
                }
        }
    }
}

Tile Map::createTile(TileType type)
{
    if (type == TileType::Grass)
        return Tile{util::AssetLoader::get().grassTile, type};
    else if (type == TileType::Dirt)
        return Tile{util::AssetLoader::get().dirtTile, type};
    else if (type == TileType::Sand)
        return Tile{util::AssetLoader::get().sandTile, type};
    else if (type == TileType::Road)
        return Tile{util::AssetLoader::get().roadTile, type};
    else if (type == TileType::BuildPoint)
        return Tile{util::AssetLoader::get().buildPoint, type};

    return Tile{util::AssetLoader::get().emptyTexture, type};
}
