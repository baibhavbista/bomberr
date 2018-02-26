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
    PowerupCheck(m_PBomber0);
    PowerupCheck(m_PBomber);
}

void Engine::PowerupCheck(Bomber* m_PBomber)
{
    Vector2i loc_player = m_PBomber->getRCVector();
    //std::cout << loc_player.x << " " << loc_player.y << std::endl;
    if(Level[loc_player.x][loc_player.y]==5)
    {
        m_PBomber->m_bombRange++;
        Level[loc_player.x][loc_player.y] = 0;
    }
    else if(Level[loc_player.x][loc_player.y]==6)
    {
        m_PBomber->m_numBombs++;
        Level[loc_player.x][loc_player.y] = 0;
    }
    else if(Level[loc_player.x][loc_player.y]==7)
    {
        m_PBomber->m_Speed += 50;
        Level[loc_player.x][loc_player.y] = 0;
    }
}


