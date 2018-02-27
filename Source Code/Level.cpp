#include "Level.h"

//creates level, reading from file_name(generally csv file) and save to matrix Level
void createLevel(std::string file_name, std::vector< std::vector<int> >& Level)
{
    std::ifstream level(file_name);
    char ch;
    int c = 0;
    while(level>>ch)
    {

        if(ch==','||ch=='\n')
            continue;
        else
        {
            Level[c/17][c%17] = int(ch) - int('0');
            c++;
        }
    }
}
