
#include "RCintoCoor.h"

sf::Vector2f rcIntoCoor(int r, int c)
{
    return sf::Vector2f(27+5+32*c, 94+3.5+32*r);
}

sf::Vector2f coorIntoGood(sf::Vector2f badCoor)
{
    int r, c;
    c = int(((badCoor.x-27-5.0)/32.0) + 0.5);
    r = int(((badCoor.y-94-3.5)/32.0) + 0.5);
    return rcIntoCoor(r, c);
}
