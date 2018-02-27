
#include "RCintoCoor.h"
#include "Engine.h"

IntRect Bomber::getCollisionRect()
{
    float x, y;
    x = m_Position.x + 10;
    y = m_Position.y + 25+5;
    return IntRect(x, y, 20, 22-5);
}

void Bomber::moveAfterCollision(IntRect Player0, IntRect block)
{
    if( m_LeftPressed ||  m_RightPressed )
    {

        stop();
        if(block.left > Player0.left)
        {
            m_LeftPressed = true;
        }

        else
        {
            m_RightPressed = true;
        }
    }

    if( m_UpPressed ||  m_DownPressed )
    {
        stop();
        if(block.top > Player0.top)
        {
            m_UpPressed = true;
        }
        else
        {
            m_DownPressed = true;
        }
    }
}

bool Bomber::collide(std::vector< std::vector<int> >* (Level), Time T)
{
    IntRect Player0 =  getCollisionRect();
    IntRect block;
    for(int r = 0; r < 11; r++)
    {
        for(int c = 0; c < 17; c++)
        {
            if((*Level)[r][c]==1 || (*Level)[r][c]==2)
            {
                Vector2f coor_tr = rcIntoCoor(r,c);
                block = IntRect(coor_tr.x, coor_tr.y, 25, 30);
                if(Player0.intersects(block))
                {
                    moveAfterCollision(Player0, block);
                    return true;
                }
            }
        }
    }

    //(m_pEngine->m_vBombs)

    for(int i = 0; i < int(m_pEngine->m_vBombs.size());i++)
    {
        if(!((m_pEngine->m_vBombs)[i]).isBlasted())
        {
            if(T.asSeconds() - ((m_pEngine->m_vBombs)[i]).m_startTime.asSeconds() > 1.0 )
            {
                Vector2f coor_tr = rcIntoCoor(((m_pEngine->m_vBombs)[i]).getCell().x, ((m_pEngine->m_vBombs)[i]).getCell().y);
                block = IntRect(coor_tr.x, coor_tr.y, 25, 30);
                if(Player0.intersects(block))
                {
                    moveAfterCollision(Player0, block);
                    return true;
                }
            }
        }
    }

    IntRect wall = TOPWALL;
    if(Player0.intersects(wall))
    {
        moveAfterCollision(Player0, wall);
        return true;
    }
    wall = BOTTOMWALL;
    if(Player0.intersects(wall))
    {
        moveAfterCollision(Player0, wall);
        return true;
    }
    wall = LEFTWALL;
    if(Player0.intersects(wall))
    {
        moveAfterCollision(Player0, wall);
        return true;
    }
    wall = RIGHTWALL;
    if(Player0.intersects(wall))
    {
        moveAfterCollision(Player0, wall);
        return true;
    }

    return false;

}

