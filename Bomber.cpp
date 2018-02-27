
#include "Bomb.h"
#include "Bomber.h"
#include "RCintoCoor.h"
#include "Engine.h"

using namespace sf;

Bomber::Bomber(Engine* pEngine, Texture& texture_bomber, Vector2f spriteDim, int color):
    m_pEngine(pEngine), Level(&(pEngine->Level)), m_TextureBomb(pEngine->m_BombTexture), m_TextureBomber(texture_bomber), m_Sprite(sf::seconds(0.2), true, false)
{
    m_lastKilledTime = pEngine->clock_explo.getElapsedTime();
    m_lives = 3;
    m_pvBombs = &(pEngine->m_vBombs);
    m_numBombs = 3;
    m_bombRange = 1;
    m_Sprite.setScale(0.8,0.8);
    //color of the bomber
    m_color = color;

    //speed of the bomber in pixels/sec
    m_Speed = 80;

    //Starting positions
    //if player(color) 0, start at top left
    //if player 1, start at bottom right
    // TODO
    //set to correct values after hud and walls
    /*
    if(color==0)
        m_Position = Vector2f(rcIntoCoor(0, 0).x-22, rcIntoCoor(0, 0).y-32) ;
    else
        m_Position = Vector2f(rcIntoCoor(10, 16).x-22, rcIntoCoor(10, 16).y-32);*/
    m_Position.x = (color==0)?(52-spriteDim.x/2):(567-spriteDim.x/2);
    m_Position.y = (color==0)?(126-spriteDim.y/2):(421-spriteDim.y/2);
    m_spriteDim = spriteDim;

    //two IntRect which denote sprite location in spritesheet
    //_down one acts as reference while the other one is constantly modified during sprite loading into animations
    IntRect m_RectSourceSprite_down = IntRect(color*3*spriteDim.x, 0, spriteDim.x, spriteDim.y);
    IntRect m_RectSourceSprite = m_RectSourceSprite_down;

    //setting the animation for movement

    //for down movement
    walkingAnimationDown.setSpriteSheet(texture_bomber);
    for(int i = 0; i < 3; i++)
    {
        walkingAnimationDown.addFrame(m_RectSourceSprite);
        m_RectSourceSprite.left += spriteDim.x;
    }
    m_RectSourceSprite = m_RectSourceSprite_down;
    m_RectSourceSprite.top += spriteDim.y;

    //for up movement
    walkingAnimationUp.setSpriteSheet(texture_bomber);
    for(int i = 0; i < 3; i++)
    {
        walkingAnimationUp.addFrame(m_RectSourceSprite);
        m_RectSourceSprite.left += spriteDim.x;
    }
    m_RectSourceSprite = m_RectSourceSprite_down;
    m_RectSourceSprite.top += 2*spriteDim.y;

    //for left movement
    walkingAnimationLeft.setSpriteSheet(texture_bomber);
    for(int i = 0; i < 3; i++)
    {
        walkingAnimationLeft.addFrame(m_RectSourceSprite);
        m_RectSourceSprite.left += spriteDim.x;
    }
    m_RectSourceSprite = m_RectSourceSprite_down;
    m_RectSourceSprite.top += 5*spriteDim.y;

    //for right movement
    walkingAnimationRight.setSpriteSheet(texture_bomber);
    for(int i = 0; i < 3; i++)
    {
        walkingAnimationRight.addFrame(m_RectSourceSprite);
        m_RectSourceSprite.left += spriteDim.x;
    }
    m_RectSourceSprite = m_RectSourceSprite_down;

    //set the pointer currentAnimation to down as the starting default
    currentAnimation = &walkingAnimationDown;


    m_RectSourceSprite = m_RectSourceSprite_down;
    m_RectSourceSprite.top += 4*spriteDim.y;
    animationDead.setSpriteSheet(texture_bomber);
    for(int i = 0; i < 2; i++)
    {
        animationDead.addFrame(m_RectSourceSprite);
        m_RectSourceSprite.left += spriteDim.x;
    }



}

//returns the sprite
//called by Engine::draw() to draw on the screen
AnimatedSprite Bomber::getSprite()
{
    return m_Sprite;
}

void Bomber::setPosition(Vector2f position)
{
    m_Sprite.setPosition(position);
}


Vector2i Bomber::getRCVector()
{
    Vector2f Position =m_Sprite.getPosition();
    if(currentAnimation == &walkingAnimationDown || currentAnimation == &walkingAnimationUp)
        Position = coorIntoGood(Vector2f(Position.x + 22, Position.y + 32));
    else if(currentAnimation == &walkingAnimationLeft)
        Position = coorIntoGood(Vector2f(Position.x + 28, Position.y + 35.2));
    else
        Position = coorIntoGood(Vector2f(Position.x + 25.6, Position.y + 34.4));
    return coorToRc(Position);
}

//returns true if no key(movement key) is pressed. Used in update function above to stop
bool Bomber::noKeyPressed()
{
    return (!(m_UpPressed || m_DownPressed || m_LeftPressed || m_RightPressed));
}

//function that updates m_Sprite(animation, position, continue or stop, etc)
void Bomber::update(Time dt)
{

    //std::cout <<"Position bomber " <<m_color << " "<< getRCVector().x << " " << getRCVector().y << std::endl;
    float elapsedTime = dt.asSeconds();
    if(m_RightPressed)
    {
        m_Position.x += m_Speed*elapsedTime;
    }
    else if(m_LeftPressed)
    {
        m_Position.x -= m_Speed*elapsedTime;
    }
    else if(m_UpPressed)
    {
        m_Position.y -= m_Speed*elapsedTime;
    }
    else if(m_DownPressed)
    {
        m_Position.y += m_Speed*elapsedTime;
    }
    m_Sprite.play(*currentAnimation);
    m_Sprite.setPosition(m_Position);
    if(noKeyPressed())
    {
        m_Sprite.stop();
    }
    m_Sprite.update(dt);
}


//functions to select animation and set and reset the boolean variables defined above like m_LeftPressed
void Bomber::moveLeft()
{
    currentAnimation = &walkingAnimationLeft;
    m_LeftPressed = true;
}
void Bomber::stopLeft()
{
    m_LeftPressed = false;
}

void Bomber::moveRight()
{
    currentAnimation = &walkingAnimationRight;
    m_RightPressed = true;
}
void Bomber::stopRight()
{
    m_RightPressed = false;
}

void Bomber::moveUp()
{
    currentAnimation = &walkingAnimationUp;
    m_UpPressed = true;
}
void Bomber::stopUp()
{
    m_UpPressed = false;
}

void Bomber::moveDown()
{
    currentAnimation = &walkingAnimationDown;
    m_DownPressed = true;
}
void Bomber::stopDown()
{
    m_DownPressed = false;
}



void Bomber::stop()
{
    m_DownPressed = false;
    m_UpPressed = false;
    m_LeftPressed = false;
    m_RightPressed = false;
    m_Sprite.stop();
}


void Bomber::dropBomb(Time start_time)
{
    if(m_numBombs > 0)
    {
        Vector2f Position =m_Sprite.getPosition();
        Position = coorIntoGood(Vector2f(Position.x + 15, Position.y + 15));
        Vector2i rc = coorToRc(Position);
        std::cout << "Bomb location" << rc.x << " " << rc.y << std::endl;
        /*if(currentAnimation==&walkingAnimationDown)
            Position.x += 1;
        else if(currentAnimation==&walkingAnimationUp)
            Position.x -= 1;
        else if(currentAnimation==&walkingAnimationRight)
            Position.y += 1;
        else if(currentAnimation==&walkingAnimationLeft)
            Position.y -= 1;
        */
        if((*Level)[rc.x][rc.y]==0)
        {
            Position = rcIntoCoor(rc.x, rc.y);
            m_pvBombs->push_back(Bomb(m_pEngine, this, Position, m_bombRange, start_time));
            m_numBombs--;
            std::cout << "inside funcn dropbomb : " << m_numBombs << std::endl;
        }
    }
}

void Bomber::die()
{
    if(m_pEngine->clock_explo.getElapsedTime().asSeconds() - m_lastKilledTime.asSeconds() > 1)
    {
        m_lastKilledTime = m_pEngine->clock_explo.getElapsedTime();
        m_lives--;
        std::cout <<"died: " << (m_lives) << "lives left" << std::endl;
        if(m_lives==0)
        {
            m_Sprite.play(animationDead);
            m_pEngine->gameOver(m_color+1);
        }
    }

}


