#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "AnimatedSprite.hpp"
#include "Animation.hpp"
#include <vector>
using namespace sf;

class Bomb;
class Engine;

//global variables for the IntRect corresponding to walls
const IntRect TOPWALL(0, 0, 608, 94);
const IntRect BOTTOMWALL(0, 450, 608, 27);
const IntRect LEFTWALL(0, 0, 27, 481);
const IntRect RIGHTWALL(578, 0, 27, 481);

class Bomber
{
private:

    Engine* m_pEngine;
    //this vector holds the x and y position of the sprite
    Vector2f m_Position;

    //vector that has the bombs
    std::vector<Bomb>* m_pvBombs;
    //num of bombs
    int m_numBombs;
    int m_bombRange;
    int m_lives;
    //booleans that are set when have to move in a certain direction
    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_UpPressed;
    bool m_DownPressed;

    std::vector< std::vector<int> >* Level;


    Vector2f m_spriteDim;

    AnimatedSprite m_Sprite;

    //speed of the bomber in pixels/sec
    float m_Speed;

    //Texture pointer for the bomber
    Texture& m_TextureBomber;
    Texture& m_TextureBomb;

    //animations for the movement
    Animation walkingAnimationDown, walkingAnimationUp, walkingAnimationLeft, walkingAnimationRight;

    //animation current movement
    Animation* currentAnimation;

public:
    friend Bomb;
    friend Engine;
    //Color of the bomber. 0 White, 1 Black, 2 Blue, 3 Red
    int m_color;

    Bomber(Engine* pEngine, Texture& texture_bomber, Vector2f spriteDim, int color);


    //gives position vector of the sprite
    IntRect getCollisionRect();

    //returns the sprite
    //called by Engine::draw() to draw on the screen
    AnimatedSprite getSprite();

    Vector2i getRCVector();

    //returns true if no key(movement key) is pressed. Used in update function above to stop
    bool noKeyPressed();

    void moveAfterCollision(IntRect Player0, IntRect block);

    bool collide(std::vector< std::vector<int> >* Level);

    //function that updates m_Sprite(animation, position, continue or stop, etc)
    void update(Time dt);

    //functions to select animation and set and reset the boolean variables defined above like m_LeftPressed
    void moveLeft();
    void stopLeft();
    void moveRight();
    void stopRight();
    void moveUp();
    void stopUp();
    void moveDown();
    void stopDown();
    void stop();

    void dropBomb(Time start_time);

    void die();
};
