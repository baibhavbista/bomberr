#include "Engine.h"
void Engine::input()
{
    if(Keyboard::isKeyPressed(Keyboard::Escape))
    {
        m_Window.close();
    }
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
}
