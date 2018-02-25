#include "Breakeable.h"

Breakeable::Breakeable(int ro, int co, int pow_up):m_r(ro), m_c(co), m_broken(false), m_powerup(pow_up)
{
    Texture m_texture;
}

bool Breakeable::isBroken()
{
    return m_broken;
}

IntRect Breakeable::getIntRect()
{
    Vector2f coor_tr = rcIntoCoor(m_r, m_c);
    IntRect block(coor_tr.x, coor_tr.y, 25, 30);
    return block;
}

Sprite Breakeable::getSprite()
{

}
