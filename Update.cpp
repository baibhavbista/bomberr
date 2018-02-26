#include "Engine.h"
//function that is called in every game loop, from Engine::start()
//calls the update functions of the players/enemies/(bombs?)
void Engine::update(Time dt, Time t)
{
    m_PBomber->update(dt);
    m_PBomber0->update(dt);
    for(int i = 0; i < int((*m_pvBombs).size()); i++)
    {
        if(!((*m_pvBombs)[i]).isBlasted())
        {
            (*m_pvBombs)[i].update(dt, t);
        }
    }

}

