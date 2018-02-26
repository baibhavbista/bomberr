
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
            std::cout << "R" << std::endl;
            //moveLeft();
            m_LeftPressed = true;
        }

        else
        {
            std::cout << "L" << std::endl;
            //moveRight();
            m_RightPressed = true;
        }
    }

    if( m_UpPressed ||  m_DownPressed )
    {
        stop();
        if(block.top > Player0.top)
        {

            std::cout << "D" << std::endl;
            //moveUp();
            m_UpPressed = true;
        }
        else
        {
            std::cout << "U" << std::endl;
            //moveDown();
            m_DownPressed = true;
        }
    }
}

bool Bomber::collide(std::vector< std::vector<int> >& Level)
{
    IntRect Player0 =  getCollisionRect();
    IntRect block;
    for(int r = 0; r < 11; r++)
    {
        for(int c = 0; c < 17; c++)
        {
            if(Level[r][c]==1 || Level[r][c]==2)
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
/*
    for(int i = 0; i < int((pvBlocksBreakable)->size()); i++)
    {
        Breakeable block = ((*pvBlocksBreakable)[i]);
        IntRect block_rect = block.getIntRect();
        if(!block.isBroken())
        {
            if(Player0.intersects(block_rect))
            {
                moveAfterCollision(Player0, block_rect);
                return true;
            }
        }

    }*/
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

