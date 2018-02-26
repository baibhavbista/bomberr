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

void Explosion::destroyBombsInCell(Vector2i currCell)
{
    for(int i = 0; i < int((*pvBombs).size()); i++)
    {
        Vector2i other_bomb_cell = (*pvBombs)[i].getCell();
        if(other_bomb_cell.x == currCell.x && other_bomb_cell.y == currCell.y && !(((*pvBombs)[i]).isBlasted()))
            ((*pvBombs)[i]).blast();
    }
}

/*void Explosion::killPlayerinCell(Vector2i currCell)
{

}*/

bool Explosion::randomPowerUpDestroy(Vector2i currCell)
{
    if((*Level)[currCell.x][currCell.y]==1)
    {
        (*Level)[currCell.x][currCell.y] = random();
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
        if(currCell.y<0 ||currCell.x < 0 || currCell.x > 10 ||currCell.y > 16||(*Level)[currCell.x][currCell.y]==2)
            break;

        destroyBombsInCell(currCell);
        if(randomPowerUpDestroy(currCell))
            break;
        std::cout << currCell.x << " " << currCell.y << std::endl;
    }
}

Explosion::Explosion(Vector2i start_cell, int blast_range, std::vector< std::vector<int> >* Levell, std::vector<Bomb>* pvbombs):
        m_startCell(start_cell), m_blastRange(blast_range), Level(Levell), pvBombs(pvbombs)
{

    explodeDirection(m_startCell, Vector2i(0, -1));
    explodeDirection(m_startCell, Vector2i(0, +1));
    explodeDirection(m_startCell, Vector2i(+1, 0));
    explodeDirection(m_startCell, Vector2i(-1, 0));

}
