#include <SFML/Graphics.hpp>
#include "Bomber.h"
using namespace sf;

Bomber::Bomber(Texture& texture_bomber, IntRect rectSourceSprite):m_TextureBomber(texture_bomber), m_Sprite(sf::seconds(0.2), true, false)
{
    m_RectSourceSprite_down = rectSourceSprite;
    m_RectSourceSprite = rectSourceSprite;

    float x = 768/12, y = 384/6;

    walkingAnimationDown.setSpriteSheet(texture_bomber);
    for(int i = 0; i < 3; i++)
    {
        walkingAnimationDown.addFrame(m_RectSourceSprite);
        m_RectSourceSprite.left += x;
    }
    m_RectSourceSprite = m_RectSourceSprite_down;
    m_RectSourceSprite.top += y;

    walkingAnimationUp.setSpriteSheet(texture_bomber);
    for(int i = 0; i < 3; i++)
    {
        walkingAnimationUp.addFrame(m_RectSourceSprite);
        m_RectSourceSprite.left += x;
    }
    m_RectSourceSprite = m_RectSourceSprite_down;
    m_RectSourceSprite.top += 2*y;

    walkingAnimationLeft.setSpriteSheet(texture_bomber);
    for(int i = 0; i < 3; i++)
    {
        walkingAnimationLeft.addFrame(m_RectSourceSprite);
        m_RectSourceSprite.left += x;
    }
    m_RectSourceSprite = m_RectSourceSprite_down;
    m_RectSourceSprite.top += 5*y;

    walkingAnimationRight.setSpriteSheet(texture_bomber);
    for(int i = 0; i < 3; i++)
    {
        walkingAnimationRight.addFrame(m_RectSourceSprite);
        m_RectSourceSprite.left += x;
    }
    m_RectSourceSprite = m_RectSourceSprite_down;

    currentAnimation = &walkingAnimationDown;

    m_Speed = 200;
    m_Position.x = 50;
    m_Position.y = 50;
}

AnimatedSprite Bomber::getSprite()
{
    return m_Sprite;
}

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

bool Bomber::noKeyPressed()
{
    return (!(m_UpPressed || m_DownPressed || m_LeftPressed || m_RightPressed));
}


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

