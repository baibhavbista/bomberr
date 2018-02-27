#include "Engine.h"
#include "Bomb.h"
#include "Bomber.h"
#include "RCintoCoor.h"

#include "Explosion.h"

Bomb::Bomb(Engine* pEngine, Bomber* pBomber, Vector2f position, int range, sf::Time start_time):
    m_pEngine(pEngine), m_Texture(m_pEngine->m_BombTexture), m_Sprite(sf::seconds(0.8), true, false), m_pvBombs()
{
    cell = coorToRc(position);
    Level = &(m_pEngine->Level);
    m_blasted = false;
    m_pvBombs = &(m_pEngine->m_vBombs);

    m_pBomber = pBomber;
    m_Position = position;
    m_range = range;
    m_startTime = start_time;
    IntRect m_RectSourceSprite = IntRect(0, 0, 32, 32);
    m_bombAnimation.setSpriteSheet(m_Texture);
    for(int i = 0; i < 7; i++)
    {
        m_bombAnimation.addFrame(m_RectSourceSprite);
        m_RectSourceSprite.left += 32;
    }


}

AnimatedSprite Bomb::getSprite()
{
    return m_Sprite;
}

Vector2i Bomb::getCell()
{
    return cell;
}

void Bomb::update(Time dt, Time time)
{
    float totalTime = time.asSeconds();
    m_Sprite.play(m_bombAnimation);
    m_Sprite.setPosition(m_Position);
    m_Sprite.update(dt);
    if(totalTime - m_startTime.asSeconds() >= 3.5)
        blast();
}

void Bomb::blast()
{
    m_blasted = true;
    Explosion(m_pEngine, cell, m_range);
    m_pBomber->m_numBombs++;


}

bool Bomb::isBlasted()
{
    return m_blasted;
}

