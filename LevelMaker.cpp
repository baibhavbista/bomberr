#include "LevelMaker.h"

LevelMaker::LevelMaker()
{
    std::ifstream level("Levels/1.csv");
    if(!level)
    {
        std::cout << "Unable to open file " << std::endl;
    }
    char ch;
    int c = 0;
    while(!level)
    {
        level.get(ch);
        if(ch==','||ch=='\n')
            continue;
        else
        {
            if(ch=='1')
            {
                vBlocksBreakable.push_back(Breakeable(c/8,c%8));
            }
            c++;
        }
    }
}

std::vector<Breakeable>* LevelMaker::getVBlocksBreakable()
{
    return &vBlocksBreakable;
}
