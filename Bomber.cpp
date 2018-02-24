
#include "Bomber.h"
using namespace sf;

Bomber::Bomber(Texture& texture_bomber, Vector2f spriteDim, int color):m_TextureBomber(texture_bomber), m_Sprite(sf::seconds(0.2), true, false)
{
    //color of the bomber
    m_color = color;

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

    //speed of the bomber in pixels/sec
    m_Speed = 200;

    //Starting positions
    //if player(color) 0, start at top left
    //if player 1, start at bottom right
    // TODO
    //set to correct values after hud and walls
    m_Position.x = (color==0)?(50):(560);
    m_Position.y = (color==0)?(50):(350);
}

//returns the sprite
//called by Engine::draw() to draw on the screen
AnimatedSprite Bomber::getSprite()
{
    return m_Sprite;
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
