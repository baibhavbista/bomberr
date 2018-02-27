#include "Explosion.h"
#include "Bomb.h"
#include "Engine.h"

int powerup_random()
{
    int random1 = rand()%20;
    //std::cout << random << std::endl;
    if(random1 == 5||random1==6||random1==7)
    {
        return random1;
    }
    else
    {
        return 0;
    }
}

void Explosion::destroyBombsInCell(Vector2i currCell)
{
    for(int i = 0; i < int((m_pEngine->m_vBombs).size()); i++)
    {
        Vector2i other_bomb_cell = ((m_pEngine->m_vBombs))[i].getCell();
        if(other_bomb_cell.x == currCell.x && other_bomb_cell.y == currCell.y && !(((m_pEngine->m_vBombs))[i].isBlasted()))
            ((m_pEngine->m_vBombs)[i]).blast();
    }
}
void Explosion::killPlayerinCell(Vector2i currCell)
{
    Vector2i bomberCell = m_pEngine->m_PBomber->getRCVector();
    if(bomberCell.x==currCell.x && bomberCell.y == currCell.y)
    {
        m_pEngine->m_PBomber->die();
    }
    bomberCell = m_pEngine->m_PBomber0->getRCVector();
    if(bomberCell.x==currCell.x && bomberCell.y == currCell.y)
    {
        m_pEngine->m_PBomber0->die();
    }
}

bool Explosion::randomPowerUpDestroy(Vector2i currCell)
{
    if((m_pEngine->Level)[currCell.x][currCell.y]==1)
    {
        (m_pEngine->Level)[currCell.x][currCell.y] = powerup_random();
        return true;
    }
    return false;
}

void Explosion::explodeDirection(Vector2i startCell, Vector2i unitVector)
{
    Vector2i currCell = startCell;
    for(int i = 0; i < m_blastRange; i++)
    {
        currCell.x += unitVector.x;
        currCell.y += unitVector.y;
        if(currCell.y<0 ||currCell.x < 0 || currCell.x > 10 ||currCell.y > 16||(m_pEngine->Level)[currCell.x][currCell.y]==2)
            break;
        std::cout << currCell.x << " " << currCell.y << std::endl;
        int num;
        num = (unitVector.x==0)?3:2;
        if(i==m_blastRange-1)
        {
            if(unitVector.x < 0)
                num = 4;
            else if (unitVector.x > 0)
                num = 5;
            else if(unitVector.y > 0)
                num = 6;
            else
                num = 7;
        }
        (m_pEngine->explosionHelper).push_back(std::make_tuple((m_pEngine->clock_explo.getElapsedTime()), num, currCell));
        //(m_pEngine->explosionHelper).push_back(std::make_tuple((((m_pEngine->clock).getElapsedTime()), num, startCell)));
//        std::cout <<
        killPlayerinCell(currCell);
        destroyBombsInCell(currCell);
        if(randomPowerUpDestroy(currCell))
            break;
    }
}

Explosion::Explosion(Engine* pEngine, Vector2i start_cell, int blast_range):
        m_startCell(start_cell), m_blastRange(blast_range)
{

    m_pEngine = pEngine;
    killPlayerinCell(m_startCell);
    (m_pEngine->explosionHelper).push_back(std::make_tuple((m_pEngine->clock_explo.getElapsedTime()), 1, m_startCell));
    //destroyBombsInCell(m_startCell);
    explodeDirection(m_startCell, Vector2i(0, -1));
    explodeDirection(m_startCell, Vector2i(0, +1));
    explodeDirection(m_startCell, Vector2i(+1, 0));
    explodeDirection(m_startCell, Vector2i(-1, 0));

}
