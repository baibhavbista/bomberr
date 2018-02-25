#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "AnimatedSprite.hpp"
#include "Animation.hpp"
#include "Breakeable.h"
using namespace sf;
class Bomber;
int Bomber::m_numBombs;
class Bomb
{
private:
    Vector2f m_Position;
    AnimatedSprite m_Sprite;
    Bomber* m_pBomber;
    int m_range;
    sf::Time m_startTime;
    const int m_timeForBlast = 3.5;
    Texture& m_Texture;
    Animation m_bombAnimation;

public:
    Bomb(Bomber* pBomber, Texture& texture_bomb, Vector2f position, int range, sf::Time start_time);
    AnimatedSprite getSprite();
    void update(Time dt, Time time);
    void blast();

};
