#include "Bomber.h"

IntRect Bomber::getCollisionRect()
{
    float x, y;
    x = m_Position.x + 10;
    y = m_Position.y + 25+5;
    return IntRect(x, y, 20, 22-5);
}

bool Bomber::collide()
{
    IntRect Player0 =  getCollisionRect();
    bool collide = false;
    IntRect block;
    for(int r = 0; r < 5; r++)
    {
        if(collide ==true)
            break;
        for(int c = 0; c < 8; c++)
        {
            block = IntRect(63+c*64, 130+r*64, 25, 30);
            if(Player0.intersects(block))
            {
                if(collide ==true)
                    break;
                collide = true;
                if( m_LeftPressed ||  m_RightPressed )
                {
                    std::cout << "YesLR" << std::endl;
                     stop();
                    if(block.left > Player0.left)
                    {
                         moveLeft();
                    }

                    else
                    {
                         moveRight();
                    }
                }

                if( m_UpPressed ||  m_DownPressed )
                {
                     stop();
                    if(block.top > Player0.top)
                    {

                        std::cout << "YesD" << std::endl;
                         moveUp();
                    }
                    else
                    {
                        std::cout << "YesU" << std::endl;
                         moveDown();
                    }
                }
            }
        }
    }
    return collide;

}

