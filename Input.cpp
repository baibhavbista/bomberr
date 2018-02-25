
#include "Engine.h"
using namespace sf;
//function that is called in every game loop,from Engine::start()
//that calls functions in Bomber object when movement keys pressed
//one user keys left, right, up down
//other user WASD
//escape closes the program
int Engine::input(Time t)
{

    if(Keyboard::isKeyPressed(Keyboard::Escape))
    {
        m_Window.close();
    }

    if(!m_PBomber->collide(m_pvBlocksBreakable))
    {
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            m_PBomber->moveLeft();
        }
        else
        {
            m_PBomber->stopLeft();
        }
        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            m_PBomber->moveRight();
        }
        else
        {
            m_PBomber->stopRight();
        }
        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            m_PBomber->moveUp();
        }
        else
        {
            m_PBomber->stopUp();
        }
        if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            m_PBomber->moveDown();
        }
        else
        {
            m_PBomber->stopDown();
        }
        if(Keyboard::isKeyPressed(Keyboard::SemiColon))
        {
            m_PBomber->dropBomb(t);
        }
    }

    if(!m_PBomber0->collide(m_pvBlocksBreakable))
    {

        if(Keyboard::isKeyPressed(Keyboard::A))
        {
            m_PBomber0->moveLeft();
        }
        else
        {
            m_PBomber0->stopLeft();
        }
        if(Keyboard::isKeyPressed(Keyboard::D))
        {
            m_PBomber0->moveRight();
        }
        else
        {
            m_PBomber0->stopRight();
        }
        if(Keyboard::isKeyPressed(Keyboard::W))
        {
            m_PBomber0->moveUp();
        }
        else
        {
            m_PBomber0->stopUp();
        }
        if(Keyboard::isKeyPressed(Keyboard::S))
        {
            m_PBomber0->moveDown();
        }
        else
        {
            m_PBomber0->stopDown();
        }
        if(Keyboard::isKeyPressed(Keyboard::Space))
        {
            m_PBomber0->dropBomb(t);
        }
    }
    return 0;

}
