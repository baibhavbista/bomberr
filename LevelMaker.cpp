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
    while(level>>ch)
    {

        if(ch==','||ch=='\n')
            continue;
        else
        {
            if(ch=='1')
            {
                //std::cout << "(" << c/17 << ", " << c%17 << ")" <<std::endl;
                vBlocksBreakable.push_back(Breakeable(c/17,c%17));
            }
            c++;
        }
    }
}

std::vector<Breakeable>* LevelMaker::getVBlocksBreakable()
{
    return &vBlocksBreakable;
}
