#include "map.hpp"

#include "base.hpp"

Map::Map()
{
}

void Map::sortCheckpoints()
{
    std::vector<Checkpoint> newCheckpoints;
    int foundCheckpoints{};
    Tile* currentTile{entrance};

    while(foundCheckpoints != (int)checkpoints.size())
    {
        currentTile = findNextPath(currentTile);
        if(!currentTile)
            break;
        for(auto& checkpoint : checkpoints)
            if(checkpoint.getPosition() == currentTile->getPosition())
            {
                foundCheckpoints++;
                newCheckpoints.push_back(checkpoint);
            }
    }
    checkpoints = newCheckpoints;
    if(exit)
        checkpoints.push_back(Checkpoint{exit->getPosition()});
}

Tile *Map::findNextPath(Tile *tile)
{
    // jest 4 pol do przeszukania
    constexpr int directions{4};

    static std::vector<Tile*> previousTiles{};

    Tile* result{};

    sf::Vector2i mapPos = util::calculatePosition(tile->getPosition());

    sf::Vector2f pos = tile->getPosition();

    bool leftClear{};
    bool rightClear{};
    bool upClear{};
    bool downClear{};

    // sprawdzenie czy mozemy przeszukiwac pola
    if(mapPos.x - 1 >= 0)
        leftClear = true;
    if(mapPos.x + 1 <= util::mapSize.x - 1)
        rightClear = true;
    if(mapPos.y - 1 >= 0)
        upClear = true;
    if(mapPos.y - 1 <= util::mapSize.y + 1)
        downClear = true;

    bool* clear[directions] {&leftClear, &rightClear, &upClear, &downClear};

    // pozycje mapy ktore sie sprawdza. Koordynaty sa zapisane w kratkach, np. 12,6
    sf::Vector2i positions[directions]
    {
        sf::Vector2i{(int)pos.x - util::tileSize.x, (int)pos.y}, // left
        sf::Vector2i{(int)pos.x + util::tileSize.x, (int)pos.y}, // right
        sf::Vector2i{(int)pos.x, (int)pos.y - util::tileSize.y}, // up
        sf::Vector2i{(int)pos.x, (int)pos.y + util::tileSize.y} // down
    };

    // zwroci tile i sprawdzi czy ma typ checkpoint lub road
    auto getTile = [&](sf::Vector2i where, bool isClear)->Tile*
    {
        if(!isClear)
            return nullptr;
        Tile* t = findTile(where);
        if(t->getType() == TileType::Road)
            return findTile(where);
        return nullptr;
    };

    for(int i = 0; i < directions; i++)
    {
        auto currentTile = getTile(positions[i], *clear[i]);

        if(currentTile)
        {
            bool isDuplicate{};
            for(auto& i : previousTiles)
                if(currentTile == i)
                    isDuplicate = true;
            if(!isDuplicate)
            {
                result = currentTile;
                previousTiles.push_back(currentTile);
                break;
            }
        }
    }

    if(result)
        return result;
    
    return nullptr;
}

void Map::loadMap(const std::filesystem::path &path)
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
            else if (static_cast<TileType>(value) == TileType::Checkpoint)
            {
                auto checkPoint(util::calculatePosition(mapPos));
                checkpoints.emplace_back(checkPoint);
                //value = static_cast<int>(tiles.back().getType());
                value = static_cast<int>(TileType::Road);
            }
            Tile tile = createTile(static_cast<TileType>(value));
            tile.setPosition(util::calculatePosition(mapPos));
            tiles.push_back(tile);
            if (tiles.back().getType() == TileType::Entrance)
                entrance = &tiles.back();
            else if (tiles.back().getType() == TileType::Exit)
                exit = &tiles.back();
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

                    if (tiles.back().getType() == TileType::Entrance)
                        entrance = &tiles.back();
                    else if (tiles.back().getType() == TileType::Exit)
                        exit = &tiles.back();
                }
                catch (std::exception& e)
                {
                    std::cerr << "error at map loading(\\n): " << e.what() << std::endl;
                }
        }
    }
    sortCheckpoints();
}

Tile Map::createTile(TileType type)
{
    if (type == TileType::Grass)
        return Tile{util::AssetLoader::get().grassTile, type};
    else if (type == TileType::Dirt)
        return Tile{util::AssetLoader::get().dirtTile, type};
    else if (type == TileType::Sand)
        return Tile{util::AssetLoader::get().sandTile, type};
    else if (type == TileType::Road || type == TileType::Checkpoint || type == TileType::Entrance || type == TileType::Exit)
        return Tile{util::AssetLoader::get().roadTile, type};
    else if (type == TileType::BuildPoint)
        return Tile{util::AssetLoader::get().buildPoint, type};

    return Tile{util::AssetLoader::get().emptyTexture, type};
}
