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
    /*for(int r = 0; r < 11; r++)
    {
        for(int c = 0; c < 17; c++)
        {
            if(Level[r][c]>=70 && Level[r][c]< 100)
            {
                Level[r][c] -= 70;
            }
            if(Level[r][c]>= 100)
            {
                Level[r][c] -= 100;
            }
        }
    }
    Vector2i loc_player = m_PBomber0->getRCVector();
    Level[loc_player.x][loc_player.] += 70;
    //std::cout << "player 0 set" << std::endl;
    loc_player = m_PBomber->getRCVector();
    Level[loc_player.x][loc_player.y] += 100;
    */



}

