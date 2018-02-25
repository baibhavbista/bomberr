
#include "RCintoCoor.h"

sf::Vector2f rcIntoCoor(int r, int c)
{
    return sf::Vector2f(27+5+32*c, 94+3.5+32*r);
}
