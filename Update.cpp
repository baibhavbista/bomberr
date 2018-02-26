#include "Engine.h"
//function that is called in every game loop, from Engine::start()
//calls the update functions of the players/enemies/(bombs?)
void Engine::update(Time dt, Time t)
{
    m_PBomber->update(dt);
    /*
    sf::Vector2f temp = m_PBomber->getSprite().getPosition();
    temp.x += 25.6; temp.y+=25.6;
    sf::Vector2f val = coorToRc(temp);
    std::cout << val.x << " " << val.y << std::endl;
    */
    m_PBomber0->update(dt);
    for(int i = 0; i < (*m_pvBombs).size(); i++)
    {
        if(!((*m_pvBombs)[i]).isBlasted())
        {
            (*m_pvBombs)[i].update(dt, t);
        }
    }
}

