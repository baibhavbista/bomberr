#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class Bomb;
class Engine;
class Explosion
{
private:
    Engine* m_pEngine;
    Vector2i m_startCell;
    int m_blastRange;
    std::vector<Bomb>* pvBombs;
    void destroyBombsInCell(Vector2i currCell);
    bool randomPowerUpDestroy(Vector2i currCell);
    void explodeDirection(Vector2i startCell, Vector2i unitVector);

    void killPlayerinCell(Vector2i currCell);

public:
    Explosion(Engine* pEngine, Vector2i start_cell, int blast_range);


};

