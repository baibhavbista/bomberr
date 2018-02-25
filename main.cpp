
#include "Engine.h"

int main()
{
    std::vector<Bomb> m_vBombs;
    Engine engine(&m_vBombs);
    engine.start();
    return 0;
}
