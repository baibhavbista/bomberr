
#include "Bomb.h"
#include "Bomber.h"
#include "RCintoCoor.h"
#include "Engine.h"

using namespace sf;

Bomber::Bomber(Engine* pEngine, Texture& texture_bomber, Vector2f spriteDim, int color):
    m_pEngine(pEngine), Level(&(pEngine->Level)), m_TextureBomb(pEngine->m_BombTexture), m_TextureBomber(texture_bomber), m_Sprite(sf::seconds(0.2), true, false)
{
    //set up bomber variables
    m_lastKilledTime = pEngine->clock_explo.getElapsedTime();
    m_lives = 3;
    m_pvBombs = &(pEngine->m_vBombs);
    m_numBombs = 3;
    m_bombRange = 1;

    //scale down sprite for bomber since high res compared to other sprites
    m_Sprite.setScale(0.8,0.8);

    //color of the bomber
    m_color = color;

    //speed of the bomber in pixels/sec
    m_Speed = 80;

    //Starting positions
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

    //animation for death of bomber(player)
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

//sets the position of the bomber sprite to position
void Bomber::setPosition(Vector2f position)
{
    m_Sprite.setPosition(position);
}

//returns Vector2i (row, column) of the bomber
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


//function to stop all movement of the bomber
//sets all movement booleans to false
//stops animation of animated sprite
void Bomber::stop()
{
    m_DownPressed = false;
    m_UpPressed = false;
    m_LeftPressed = false;
    m_RightPressed = false;
    m_Sprite.stop();
}

//drops bombs
//calls constructor for bomb and pushes the bomb to v_Bombs through m_pvBombs
void Bomber::dropBomb(Time start_time)
{
    if(m_numBombs > 0)
    {
        Vector2f Position =m_Sprite.getPosition();
        Position = coorIntoGood(Vector2f(Position.x + 15, Position.y + 15));
        Vector2i rc = coorToRc(Position);
        if((*Level)[rc.x][rc.y]==0)
        {
            Position = rcIntoCoor(rc.x, rc.y);
            m_pvBombs->push_back(Bomb(m_pEngine, this, Position, m_bombRange, start_time));
            m_numBombs--;
        }
    }
}

//function called when player dies or gets damaged(health decrease)
void Bomber::die()
{
    //if has been 1 s since last died
    if(m_pEngine->clock_explo.getElapsedTime().asSeconds() - m_lastKilledTime.asSeconds() > 1)
    {
        //sets last killed time to current time
        m_lastKilledTime = m_pEngine->clock_explo.getElapsedTime();

        //decreases lives
        m_lives--;

        if(m_lives==0)
        {
            m_Sprite.play(animationDead);
            //calls Engine::gameOver passing current bomber as loser.
            m_pEngine->gameOver(m_color+1);
        }
    }
}


