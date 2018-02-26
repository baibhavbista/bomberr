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

public:
    Explosion(Vector2i start_cell, int blast_range, std::vector< std::vector<int> >* Levell, std::vector<Bomb>* pvbombs);

};

