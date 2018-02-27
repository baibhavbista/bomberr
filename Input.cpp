
#include "Engine.h"
using namespace sf;
//function that is called in every game loop,from Engine::start()
//that calls functions in Bomber object when movement keys pressed
//one user keys left, right, up down
//other user WASD
//escape closes the program
void Engine::input(Time t, Clock timer)
{
    if(m_gameOver)
    {
        while(m_Window.pollEvent(event))
        {
            //std::cout << "poll_event" << std::endl;
            if((event.type== Event::KeyPressed &&(event.key.code == sf::Keyboard::Return))||event.type==Event::Closed)
            {
                m_Window.close();
            }
        }
    }
    else if(m_gamePaused)
    {
        while(m_Window.pollEvent(event))
        {
            //std::cout << "poll_event" << std::endl;
            if((event.type== Event::KeyReleased && (event.key.code == sf::Keyboard::Escape))||(event.type==Event::Closed))
            {
                m_Window.close();
            }
            if(event.type==Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::Return)
                {
                    resume();
                }

            }
        }
    }
    else
    {
        if(!m_PBomber->collide(&Level, timer.getElapsedTime()))
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


        }

        if(!m_PBomber0->collide(&Level,timer.getElapsedTime()))
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

        }
        while(m_Window.pollEvent(event))
        {
            //std::cout << "poll_event" << std::endl;
            if((event.type== Event::KeyPressed && event.key.code == sf::Keyboard::Escape)||event.type==Event::Closed)
            {
                pause();
            }
            if(event.type==Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::SemiColon)
                {
                    //std::cout << "semicolon" << std::endl;
                    m_PBomber->dropBomb(t);
                }
                if(event.key.code == sf::Keyboard::Space)
                {
                    m_PBomber0->dropBomb(t);
                }
            }

        }
    }

}
