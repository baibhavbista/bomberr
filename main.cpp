
#include "Engine.h"

int main()
{
    std::vector<Bomb> m_vBombs;
    int Level[17][11];
    Engine engine(&m_vBombs);
    engine.start();
    return 0;
}
