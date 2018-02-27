#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class Bomb;
class Engine;

//Explosion class that causes the destruction and visual effects of bombs exploding
class Explosion
{
private:
    Engine* m_pEngine;
    Vector2i m_startCell;
    int m_blastRange;
    std::vector<Bomb>* pvBombs;

    //explodes in a particular direction depending on the unit vector specified
    //In the unit vector, one component must be 0 and the other 1 or -1
    void explodeDirection(Vector2i startCell, Vector2i unitVector);

    //destroys the bombs in given cell currCell, called by the constructor
    void destroyBombsInCell(Vector2i currCell);

    //if the currCell had a breakable block, randomly choose whether or not to put a Powerup there, and which one to put
    bool randomPowerUpDestroy(Vector2i currCell);

    //if the player is in the currCell, this function kills(damages) the Player
    void killPlayerinCell(Vector2i currCell);

public:
    //constructor for the Explosion class
    //does the whole work of the explosion
    //calls the killPlayerinCell for the start_cell, and calls explodeDirection in 4 directions upto blast_range
    Explosion(Engine* pEngine, Vector2i start_cell, int blast_range);


};

