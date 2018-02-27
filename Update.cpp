#include "Engine.h"
#include <sstream>
//function that is called in every game loop, from Engine::start()
//calls the update functions of the players/enemies/(bombs?)


void Engine::update(Time dt, Time t)
{
    updateHUD();
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
        m_PBomber->m_Speed += 25;
        Level[loc_player.x][loc_player.y] = 0;
    }
}

void Engine::updateHUD()
{
    std::stringstream ss;
    int seconds = displayTimer.GetElapsedSeconds();
    seconds = 2*60 - seconds;
    if(seconds < 0)
        gameOver(0);
    else
    {
        ss << "Time left ";
        ss.width(2);
        ss.fill('0');
        ss << seconds/60;
        ss << " : ";
        ss.width(2);
        ss << seconds%60;
        timeDisplayText.setString(ss.str());
        //std::cout << seconds/60 << " " << seconds%60 << std::endl;
        ss.str("");
        ss << (m_PBomber0->m_lives);
        player0LifeText.setString(ss.str());
        ss.str("");
        ss << (m_PBomber->m_lives);
        player1LifeText.setString(ss.str());
    }

}



