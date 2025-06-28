#pragma once
#include  "archers/archer.hpp"
#include <memory>

class Tower
{
    std::unique_ptr<Archer> archer;
public:
    Tower();
    ~Tower();
};