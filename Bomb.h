#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "AnimatedSprite.hpp"
#include "Animation.hpp"

using namespace sf;
class Bomber;
class Engine;
class Bomb
{
private:
    Engine* m_pEngine;
    Vector2i cell;
    std::vector<Bomb>* m_pvBombs;
    std::vector< std::vector<int> >* Level;
    Vector2f m_Position;
    Texture& m_Texture;
    AnimatedSprite m_Sprite;
    Bomber* m_pBomber;
    bool m_blasted;
    int m_range;
    sf::Time m_startTime;
    const int m_timeForBlast = 3.5;
    Animation m_bombAnimation;

public:
    Bomb(Engine* pEngine, Bomber* pBomber, Vector2f position, int range, sf::Time start_time);
    AnimatedSprite getSprite();
    void update(Time dt, Time time);
    Vector2i getCell();
    void blast();
    bool isBlasted();
    //friend class Explosion;

};
