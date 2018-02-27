#include "Explosion.h"
#include "Bomb.h"
#include "Engine.h"

//generates random number
//if num generated ==5 or 6 or 7, corresponds to respective powerup, and returns the same
//else returns 0
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

//destroys the bombs in given cell currCell, called by the constructor
void Explosion::destroyBombsInCell(Vector2i currCell)
{
    //for bomb in Engine::vBombs
    for(int i = 0; i < int((m_pEngine->m_vBombs).size()); i++)
    {
        //get cell i.e. (row, col) of the bomb
        Vector2i other_bomb_cell = ((m_pEngine->m_vBombs))[i].getCell();

        //if cell we got is our currCell and bomb not blasted yet, blast the bomb
        if(other_bomb_cell.x == currCell.x && other_bomb_cell.y == currCell.y && !(((m_pEngine->m_vBombs))[i].isBlasted()))
            ((m_pEngine->m_vBombs)[i]).blast();
    }
}

//if the player is in the currCell, this function kills(damages) the Player
void Explosion::killPlayerinCell(Vector2i currCell)
{
    //for both players, if players position(i.e.(row, column)) is the same as currCell, kill the player
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

//if the currCell had a breakable block, randomly choose whether or not to put a Powerup there, and which one to put
bool Explosion::randomPowerUpDestroy(Vector2i currCell)
{
    if((m_pEngine->Level)[currCell.x][currCell.y]==1)
    {
        (m_pEngine->Level)[currCell.x][currCell.y] = powerup_random();
        return true;
    }
    return false;
}

//explodes in a particular direction depending on the unit vector specified
//In the unit vector, one component must be 0 and the other 1 or -1
void Explosion::explodeDirection(Vector2i startCell, Vector2i unitVector)
{
    Vector2i currCell = startCell;
    for(int i = 0; i < m_blastRange; i++)
    {
        //get new cell
        currCell.x += unitVector.x;
        currCell.y += unitVector.y;

        //if currcell in not in limits, and if unbreakeable, break
        if(currCell.y<0 ||currCell.x < 0 || currCell.x > 10 ||currCell.y > 16||(m_pEngine->Level)[currCell.x][currCell.y]==2)
            break;

        //visual effects of explosion
        //integer which has the code for which explosion sprite to display
        int num;

        //if (unitVector.x==0) i.e. horizontal blast , select 3 as num
        //else, is vertical blast, so, select 2 as num
        num = (unitVector.x==0)?3:2;

        //if last in the range(since last has special sprite)
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

        //add tuple of (current time, number code for which sprite to display, position(r, c)) to Engine::explosionHelper
        (m_pEngine->explosionHelper).push_back(std::make_tuple((m_pEngine->clock_explo.getElapsedTime()), num, currCell));

        //actual effect of explosion
        //kill player if in cell
        killPlayerinCell(currCell);
        //destroy bomb if in cell
        destroyBombsInCell(currCell);

        //if cell has breakable block, destro it and stop explosion there
        if(randomPowerUpDestroy(currCell))
            break;
    }
}

//constructor for the Explosion class
//does the whole work of the explosion
//calls the killPlayerinCell for the start_cell, and calls explodeDirection in 4 directions upto blast_range
Explosion::Explosion(Engine* pEngine, Vector2i start_cell, int blast_range):
        m_startCell(start_cell), m_blastRange(blast_range)
{

    m_pEngine = pEngine;

    //handle explosion in starting cell
    killPlayerinCell(m_startCell);
    (m_pEngine->explosionHelper).push_back(std::make_tuple((m_pEngine->clock_explo.getElapsedTime()), 1, m_startCell));

    //explode in all 4 directions
    explodeDirection(m_startCell, Vector2i(0, -1));
    explodeDirection(m_startCell, Vector2i(0, +1));
    explodeDirection(m_startCell, Vector2i(+1, 0));
    explodeDirection(m_startCell, Vector2i(-1, 0));

}
