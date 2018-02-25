#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "RCintoCoor.h"
#include "AnimatedSprite.hpp"
#include "Animation.hpp"
using namespace sf;

class Breakeable
{
private:
    int m_r;
    int m_c;
    int m_powerup;
    bool m_broken;
    Sprite m_Sprite;
public:
    Breakeable(int ro, int co, int pow_up=0);
    bool isBroken();
    IntRect getIntRect();
    Sprite getSprite();
};
