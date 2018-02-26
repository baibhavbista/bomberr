#include "Explosion.h"
#include "Bomb.h"
int random()
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

Explosion::Explosion(Vector2i start_cell, int blast_range, std::vector< std::vector<int> >* Levell, std::vector<Bomb>* pvbombs):
        m_startCell(start_cell), m_blastRange(blast_range), Level(Levell), pvBombs(pvbombs)
{

    Vector2i currCell = m_startCell;
    //left
    for(int i = 0; i < m_blastRange; i++)
    {
        currCell.y -= 1;
        if(currCell.y<0 || (*Level)[currCell.x][currCell.y]==2)
            break;
        if((*Level)[currCell.x][currCell.y]!=0)
        {
            (*Level)[currCell.x][currCell.y] = random();
        }
        std::cout << currCell.x << " " << currCell.y << std::endl;
    }

    //right
    currCell = m_startCell;
    for(int i = 0; i < m_blastRange; i++)
    {
        currCell.y += 1;
        if(currCell.y>16 || (*Level)[currCell.x][currCell.y]==2)
            break;

        if((*Level)[currCell.x][currCell.y]!=0)
        {
            (*Level)[currCell.x][currCell.y] = random();
        }
        std::cout << currCell.x << " " << currCell.y << std::endl;
    }

    //up
    currCell = m_startCell;
    for(int i = 0; i < m_blastRange; i++)
    {
        currCell.x -= 1;
        if(currCell.x<0 || (*Level)[currCell.x][currCell.y]==2)
            break;
        if((*Level)[currCell.x][currCell.y]!=0)
        {
            (*Level)[currCell.x][currCell.y] = random();
        }
        std::cout << currCell.x << " " << currCell.y << std::endl;
    }

    //down
    currCell = m_startCell;
    for(int i = 0; i < m_blastRange; i++)
    {
        currCell.x += 1;
        if(currCell.x>10 || (*Level)[currCell.x][currCell.y]==2)
            break;
        if((*Level)[currCell.x][currCell.y]!=0)
        {
            (*Level)[currCell.x][currCell.y] = random();
        }
        std::cout << currCell.x << " " << currCell.y << std::endl;
    }



}
