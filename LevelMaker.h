#pragma once
#include <fstream>
#include "Breakeable.h"
#include <vector>

class LevelMaker
{
public:
    LevelMaker();
    std::vector<Breakeable>* getVBlocksBreakable();
    std::vector<Breakeable> vBlocksBreakable;

};

