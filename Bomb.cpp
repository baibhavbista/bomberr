
#include "bomb.h"
#include "bomber.h"
#include "RCintoCoor.h"

#include "Explosion.h"

Bomb::Bomb(std::vector< std::vector<int> >* Levell,Bomber* pBomber, Texture& texture_bomb, Vector2f position, int range, sf::Time start_time, std::vector<Bomb>* pvBombs):
    m_Texture(texture_bomb), m_Sprite(sf::seconds(0.8), true, false)
{
    cell = coorToRc(position);
    Level = Levell;
    m_blasted = false;
    m_pvBombs = pvBombs;

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
    Explosion(cell, m_range, Level, m_pvBombs);
    m_pBomber->m_numBombs++;

    /*for(auto a:*Level)
    {
        for(auto b:a)
        {
            std::cout << b << " ";
        }
        std::cout << std::endl;
    }*/
}

bool Bomb::isBlasted()
{
    return m_blasted;
}

