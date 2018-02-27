
#include "RCintoCoor.h"
#include "Engine.h"

//returns collision Rectangle(an IntRect corresponding to the bombers area)
IntRect Bomber::getCollisionRect()
{
    float x, y;
    x = m_Position.x + 10;
    y = m_Position.y + 25+5;
    return IntRect(x, y, 20, 22-5);
}

//causes movement after collision
//takes the intRect of the player and the block as arguments
//called from within Bomber::collide()
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

//handles collision with blocks(breakeable, solid) and walls
//takes the vector of vectors of int "Level" as argument
bool Bomber::collide(std::vector< std::vector<int> >* (Level), Time T)
{
    IntRect Player0 =  getCollisionRect();
    IntRect block;

    //handles collision with breakeable blocks(1) and unbreakeable blocks(2)
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

    //handles collision with bombs(since 1 s after their deployment)
    for(int i = 0; i < int(m_pEngine->m_vBombs.size());i++)
    {
        //checks if bomb blasted or not, goes in only if not blasted yet
        if(!((m_pEngine->m_vBombs)[i]).isBlasted())
        {
            //if it has been 1 sec since deployment of bomb
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

    //handles collision with walls: TOPWALL, BOTTOMWALL, LEFTWALL and RIGHTWALL respectively
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

