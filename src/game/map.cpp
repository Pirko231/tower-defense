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
    std::vector<Tile*> previousTiles{};

    while(foundCheckpoints != (int)checkpoints.size())
    {
        currentTile = findNextPath(currentTile, previousTiles);
        if(!currentTile)
            break;
        for(auto& checkpoint : checkpoints)
            if(checkpoint.getPosition() == currentTile->getPosition())
            {
                foundCheckpoints++;
                newCheckpoints.push_back(checkpoint);
            }
    }
    checkpoints.clear();
    checkpoints = newCheckpoints;
    if(exit)
        checkpoints.push_back(Checkpoint{exit->getPosition()});
}

Tile *Map::findNextPath(Tile *tile, std::vector<Tile*>& previousTiles)
{
    // jest 4 pol do przeszukania
    constexpr int directions{4};

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

void Map::loadMap(const std::filesystem::path &path, int numberOfDecorations)
{
    tiles.clear();
    tiles.reserve(600);
    buildPoints.clear();
    checkpoints.clear();
    entrance = nullptr; exit = nullptr;

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
    placeDecorations(numberOfDecorations);
}

Tile Map::createTile(TileType type)
{
    if (type == TileType::Grass)
        return Tile{util::AssetLoader::get().grassTile, type};
    else if (type == TileType::Dirt)
        return Tile{util::AssetLoader::get().dirtTile, type};
    else if (type == TileType::Sand)
        return Tile{util::AssetLoader::get().sandTile, type};
    else if (type == TileType::PinkGrass)
        return Tile{util::AssetLoader::get().pinkGrassTile, type};
    else if (type == TileType::Ice)
        return Tile{util::AssetLoader::get().iceTile, type};
    else if (type == TileType::HellGrass)
        return Tile{util::AssetLoader::get().hellTile, type};
    else if (type == TileType::Road || type == TileType::Checkpoint || type == TileType::Entrance || type == TileType::Exit)
        return Tile{util::AssetLoader::get().roadTile, type};
    else if (type == TileType::BuildPoint)
        return Tile{util::AssetLoader::get().buildPoint, type};

    return Tile{util::AssetLoader::get().emptyTexture, type};
}

void Map::placeDecorations(int amount)
{
    decorations.clear();
    auto textures = getDecorationSet(determineMainTileType());

    auto randPosition = [&]()->sf::Vector2f
    {
        sf::Vector2f position = {static_cast<float>(std::rand() % util::mapSize.x), static_cast<float>(std::rand() % util::mapSize.y)};
        position = sf::Vector2f{position.x * (float)util::tileSize.x, position.y * (float)util::tileSize.y};
        position += {static_cast<float>(std::rand() % util::tileSize.x), static_cast<float>(std::rand() % util::tileSize.y)};
        return position;
    };

    auto checkNearbyTypes = [&](sf::Vector2f pos)->bool
    {
        // sprawdzamy 8 pol obok siebie
        sf::Vector2i mapPos = util::calculatePosition(pos);
        mapPos.x -= 1; mapPos.y -= 1;
        pos -= (sf::Vector2f)util::tileSize;
        if(mapPos.x < 0 || mapPos.y < 0 || mapPos.x + 3 > util::mapSize.x || mapPos.y + 3 > util::mapSize.y)
        {
            mapPos.x += 1; mapPos.y += 1; // przywracamy do poprzedniego stanu i odzyszkujemy gwarancje popprawnych koordynatow
            pos += (sf::Vector2f)util::tileSize;
            TileType type = findTile((sf::Vector2i)pos)->getType();
            if(type == TileType::Road || getCheckpoint(mapPos) || getBuildPoint(mapPos))
                return false;
            else
                return false; // true
        }

        for(int i = 0; i < 3; i++, pos.y += util::tileSize.y, mapPos.y++)
        {
            for(int j = 0; j < 3; j++, pos.x += util::tileSize.x, mapPos.x++)
            {
                TileType type = findTile((sf::Vector2i)pos)->getType();
                if(type == TileType::Road || getCheckpoint(mapPos) || getBuildPoint(mapPos))
                    return false;
            }
            pos.x -= util::tileSize.x * 3;
            mapPos.x -= 3;
        }
        return true;
    };

    for(int i = 0; i < amount; i++)
    {
        decorations.push_back(static_cast<sf::Sprite>((*(textures.begin() + std::rand() % textures.size()))));
        
        sf::Vector2f position = randPosition();
        while(!checkNearbyTypes(position))
            position = randPosition();
        
        
        decorations.back().setPosition(position);
    }
}

std::vector<sf::Sprite> Map::getDecorationSet(TileType type) const
{
    if(type == TileType::Grass)
    {
        sf::Sprite summerBush{util::AssetLoader::get().summerBush};
        summerBush.setScale({0.7f,0.7f});
        sf::Sprite summerTree{util::AssetLoader::get().summerTree};
        return {summerBush, summerTree};
    }
    if(type == TileType::Sand)
    {
        sf::Sprite cactus1 {util::AssetLoader::get().cactus1};
        cactus1.setScale({2.8f,3.2f});
        sf::Sprite cactus2 {util::AssetLoader::get().cactus2};
        cactus2.setScale({4.f,4.f});
        return {cactus1, cactus2};
    }
    if(type == TileType::Ice)
    {
        sf::Sprite winterTree{util::AssetLoader::get().winterTree};
        sf::Sprite winterTrunk{util::AssetLoader::get().winterTrunk};
        return {winterTree, winterTrunk};
    }
    if(type == TileType::PinkGrass)
    {
        sf::Sprite moldTree1{util::AssetLoader::get().moldTree1};
        sf::Sprite moldTree2{util::AssetLoader::get().moldTree2};
        return {moldTree1, moldTree2};
    }
    if(type == TileType::HellGrass)
    {
        sf::Sprite hellTree{util::AssetLoader::get().hellTree};
        sf::Sprite hellTrunk{util::AssetLoader::get().hellTrunk};
        return {hellTree, hellTrunk};
    }
        
    return {(sf::Sprite)util::AssetLoader::get().attackIcon};
}

TileType Map::determineMainTileType() const
{
    std::unordered_map<TileType, /*amount*/int> tileAmount;
    
    for(auto& tile : tiles)
    {
        if(tile.getType() != TileType::Road && tile.getType() != TileType::Entrance && tile.getType() != TileType::Exit && tile.getType() != TileType::BuildPoint)
            tileAmount[tile.getType()]++;
    }

    return std::max_element(tileAmount.begin(), tileAmount.end(), []
    (const auto &p1, const auto &p2){return p1.second < p2.second;})->first;

}
