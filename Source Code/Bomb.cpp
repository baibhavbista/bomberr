#include "Engine.h"
#include "Bomb.h"
#include "Bomber.h"
#include "RCintoCoor.h"
#include "Explosion.h"

//constructor for bomb. called from within a bomber class
//the bomb object has range "range", and start_time
//new bombs are automatically added to Engine::std::vector<Bomb> m_vBombs;
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

//returns the animated sprite of the bomb
AnimatedSprite Bomb::getSprite()
{
    return m_Sprite;
}

//returns the position of the bomb in the form of Vector2i(row, column)
Vector2i Bomb::getCell()
{
    return cell;
}

//update the bomb. Takes arguments dt(time since last loop, required for animated class) and time, which is the total time
void Bomb::update(Time dt, Time time)
{
    float totalTime = time.asSeconds();
    m_Sprite.play(m_bombAnimation);
    m_Sprite.setPosition(m_Position);
    m_Sprite.update(dt);
    if(totalTime - m_startTime.asSeconds() >= 3.5)
        blast();
}

//blasts the bomb. called when time of the bomb is finished
//creates an exlopsion object that does the work of blasting, and sets the bool m_blasted to true so that, it doesn't blast again.
void Bomb::blast()
{
    m_blasted = true;
    Explosion(m_pEngine, cell, m_range);
    m_pBomber->m_numBombs++;


}

//returns the private bool m_blasted, that signifies if the bomb has blasted or not
bool Bomb::isBlasted()
{
    return m_blasted;
}

