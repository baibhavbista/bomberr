#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class Bomb;

class Explosion
{
private:
    Vector2i m_startCell;
    int m_blastRange;
    std::vector< std::vector<int> >* Level;
    std::vector<Bomb>* pvBombs;
    void destroyBombsInCell(Vector2i currCell);
    bool randomPowerUpDestroy(Vector2i currCell);
    void explodeDirection(Vector2i startCell, Vector2i unitVector);
    void killPlayerinCell(Vector2i currCell);


public:
    Explosion(Vector2i start_cell, int blast_range, std::vector< std::vector<int> >* Levell, std::vector<Bomb>* pvbombs);


};

