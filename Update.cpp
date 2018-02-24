#include "Engine.h"
//function that is called in every game loop, from Engine::start()
//calls the update functions of the players/enemies/(bombs?)
void Engine::update(Time dt)
{
    m_PBomber->update(dt);
    m_PBomber0->update(dt);
}
