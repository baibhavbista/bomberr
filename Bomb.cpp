#include "bomb.h"

Bomb::Bomb(Bomber* pBomber, Texture& texture_bomb, Vector2f position, int range, sf::Time start_time):m_Texture(texture_bomb), m_Sprite(sf::seconds(0.5), true, false)
{
    m_pBomber = pBomber;
    m_Position = position;
    m_range = range;
    m_startTime = start_time;
    IntRect m_RectSourceSprite = IntRect(0, 0, 32, 32);
    m_bombAnimation.setSpriteSheet(texture_bomb);
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

void Bomb::update(Time dt, Time time)
{
    float dTime = dt.asSeconds();
    float totalTime = time.asSeconds();
    m_Sprite.play(m_bombAnimation);
    m_Sprite.setPosition(m_Position);
    m_Sprite.update(dt);
    if(totalTime - m_startTime.asSeconds() >= 3.5)
        blast();
}

void Bomb::blast()
{

    //
    m_pBomber->m_numBombs++;
}
