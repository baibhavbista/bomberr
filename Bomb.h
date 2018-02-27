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
    //constructor for bomb. called from within a bomber class
    //the bomb object has range "range", and start_time
    //new bombs are automatically added to Engine::std::vector<Bomb> m_vBombs;
    Bomb(Engine* pEngine, Bomber* pBomber, Vector2f position, int range, sf::Time start_time);

    //returns the animated sprite of the bomb
    AnimatedSprite getSprite();

    //update the bomb. Takes arguments dt(time since last loop, required for animated class) and time, which is the total time
    void update(Time dt, Time time);

    //returns the position of the bomb in the form of Vector2i(row, column)
    Vector2i getCell();

    //blasts the bomb. called when time of the bomb is finished
    //creates an exlopsion object that does the work of blasting, and sets the bool m_blasted to true so that, it doesn't blast again.
    void blast();

    //returns the private bool m_blasted, that signifies if the bomb has blasted or not
    bool isBlasted();

    friend Bomber;

};
