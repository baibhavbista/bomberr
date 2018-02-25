#include "Engine.h"
#include "Bomb.h"
#include "Bomber.h"
//function that is called in every game loop, from Engine::start()
//draws all the things
void Engine::draw()
{
    //clear white window
    m_Window.clear(Color::White);

    //draw background
    m_Window.draw(m_BackgroundSprite);
    m_Window.draw(m_FrameSprite);

    Vector2f coor_tr;
    for(int r = 0; r < 11; r++)
    {
        for(int c = 0; c < 17; c++)
        {
            if(Level[r][c] == 1)
            {
                coor_tr = rcIntoCoor(r,c);
                m_BlockSprite.setPosition(coor_tr);
                m_Window.draw(m_BlockSprite);
            }
        }
    }

/*    std::vector<Breakeable> v = *m_pvBlocksBreakable;
    for(int i = 0; i < v.size(); i++)
    {
        //std::cout << "breakable done" << std::endl;
        if(!v[i].isBroken())
        {
            //std::cout << "breakable done" << std::endl;
            m_BlockSprite.setPosition(v[i].getPosition());
            m_Window.draw(m_BlockSprite);
        }
    }*/

    //draw player 0, upscaled 1.2
    AnimatedSprite dispSprite = (m_PBomber0->getSprite());
    //dispSprite.setScale(0.8, 0.8);

    m_Window.draw(dispSprite);

    //draw player 1, upscaled 1.2
    dispSprite = (m_PBomber->getSprite());
    //dispSprite.setScale(0.8, 0.8);
    m_Window.draw(dispSprite);

    for(int i = 0; i < (*m_pvBombs).size(); i++)
    {
        if(!((*m_pvBombs)[i]).isBlasted())
        {
            dispSprite = (*m_pvBombs)[i].getSprite();
            m_Window.draw(dispSprite);
        }
    }
    //m_Window.draw(immovable_block);
    //display the window
    m_Window.display();
}
