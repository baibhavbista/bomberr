#include "Level.h"

void createLevel(char* file_name, int Level[11][17])
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
