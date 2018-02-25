
#include "RCintoCoor.h"

sf::Vector2f rcIntoCoor(int r, int c)
{
    return sf::Vector2f(27+32*c, 94+32*r);
}
