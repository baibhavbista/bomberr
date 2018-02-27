
#include "RCintoCoor.h"

//changes row r and column c into position vector2f
sf::Vector2f rcIntoCoor(int r, int c)
{
    return sf::Vector2f(27+5+32*c, 94+3.5+32*r);
}

//returns the closest good coordinate(a coordinate vector2f that is at the center of a cell) to  badCoor, a bad(not-good) coordinate
sf::Vector2i coorToRc(sf::Vector2f badCoor)
{
    badCoor = coorIntoGood(badCoor);
    int r, c;
    c = int(((badCoor.x-27-5.0)/32.0) + 0.5);
    r = int(((badCoor.y-94-3.5)/32.0) + 0.5);
    return sf::Vector2i(r, c);
}

//changes Coordinate vector2f into Vector2i(row, column). Calls coorIntoGood internally, so bad coordinate can also be passed as argument
sf::Vector2f coorIntoGood(sf::Vector2f badCoor)
{
    int r, c;
    c = (int(((badCoor.x-27-5.0)/32.0) + 0.5));
    r = int(((badCoor.y-94-3.5)/32.0) + 0.5);
    bool todo=false;
    if(r > 10)
        r =10;
    else if(r < 0)
        r = 0;

    if(c > 16)
        c = 16;
    else if(c < 0)
        c = 0;

    return rcIntoCoor(r, c);
}
