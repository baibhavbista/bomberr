#include <SFML/Graphics.hpp>
#include "Bomber.h"
using namespace sf;

Bomber::Bomber(Texture& texture_bomber, IntRect rectSourceSprite):m_TextureBomber(texture_bomber)
{
    m_RectSourceSprite_down = rectSourceSprite;
    m_RectSourceSprite = rectSourceSprite;
    m_Sprite.setTexture(m_TextureBomber);
    m_Sprite.setTextureRect(m_RectSourceSprite);
    m_Speed = 400;
    m_Position.x = 50;
    m_Position.y = 50;
}

Sprite Bomber::getSprite()
{
    return m_Sprite;
}

void Bomber::moveLeft()
{
    m_LeftPressed = true;
}
void Bomber::stopLeft()
{
    m_LeftPressed = false;
}

void Bomber::moveRight()
{
    m_RightPressed = true;
}
void Bomber::stopRight()
{
    m_RightPressed = false;
}

void Bomber::moveUp()
{
    m_UpPressed = true;
}
void Bomber::stopUp()
{
    m_UpPressed = false;
}

void Bomber::moveDown()
{
    m_DownPressed = true;
}
void Bomber::stopDown()
{
    m_DownPressed = false;
}

void Bomber::update(float elapsedTime)
{
    if(m_RightPressed)
    {
        m_Position.x += m_Speed*elapsedTime;
    }
    if(m_LeftPressed)
    {
        m_Position.x -= m_Speed*elapsedTime;
    }
    if(m_UpPressed)
    {
        m_Position.y -= m_Speed*elapsedTime;
    }
    if(m_DownPressed)
    {
        m_Position.y += m_Speed*elapsedTime;
    }
    m_Sprite.setPosition(m_Position);
}

