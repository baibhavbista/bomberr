#include "Engine.h"

using namespace sf;

Engine::Engine():Level(11, std::vector<int> (17, 0) )
{
    //resolution based on size of frame, which is (608, 416).
    m_Window.create(VideoMode(608, 416+65), "Bomber Move");

    //sets framerate to 60 fps
    m_Window.setFramerateLimit(60);

    createLevel("Levels/1.csv", Level);

    //loads background from file
    //TODO: random background
    m_BackgroundTexture.loadFromFile("backgrounds/back.png");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);

    m_BlockTexture.loadFromFile("sprites/breakable.png");
    m_BlockSprite.setTexture(m_BlockTexture);

    m_SolidBlockTexture.loadFromFile("sprites/solid.png");
    m_SolidBlockSprite.setTexture(m_SolidBlockTexture);

    m_PowerTexture5.loadFromFile("sprites/5.png");
    m_PowerSprite5.setTexture(m_PowerTexture5);

    m_PowerTexture6.loadFromFile("sprites/6.png");
    m_PowerSprite6.setTexture(m_PowerTexture6);

    m_PowerTexture7.loadFromFile("sprites/7.png");
    m_PowerSprite7.setTexture(m_PowerTexture7);

    m_ExplosionTexture.loadFromFile("sprites/explosion.png");

    m_ExplosionSprite = new Sprite[3];
    m_ExplosionSprite[0].setTexture(m_ExplosionTexture);
    m_ExplosionSprite[0].setTextureRect(IntRect(0, 0, 32, 32));
    m_ExplosionSprite[1].setTexture(m_ExplosionTexture);
    m_ExplosionSprite[1].setTextureRect(IntRect(32, 0, 32, 32));
    m_ExplosionSprite[2].setTexture(m_ExplosionTexture);
    m_ExplosionSprite[2].setTextureRect(IntRect(64, 0, 32, 32));
    //frame texture and sprite

    m_FrameTexture.loadFromFile("sprites/frame.png");
    //std::cout << "Successful" <<std::endl;

    m_FrameSprite.setTexture(m_FrameTexture);
    m_FrameSprite.setPosition(0, 65);
    m_pvBombs = &m_vBombs;

/*    m_plevel = new LevelMaker();
    m_pvBlocksBreakable = m_plevel->getVBlocksBreakable();*/
    //block textures

    //Players texture loaded
    m_PlayerTexture.loadFromFile("sprites/player.png");
    m_BombTexture.loadFromFile("sprites/bombs.png");



    //Vector that represents sprite dimensions in sprite sheet (for players/bombers)
    Vector2f spriteDim(768/12, 384/6);
    //m_pvBomber.push_back()
    m_PBomber = new Bomber(this, m_PlayerTexture, spriteDim, 1);
    m_PBomber0 = new Bomber(this, m_PlayerTexture, spriteDim, 0);
}

void Engine::start()
{
    Clock clock;
    Vector2f prev(768/12, 384/6);
    Clock timer;
    while(m_Window.isOpen())
    {
        //std::cout << timer.getElapsedTime().asSeconds() << std::endl;

        //save elapsed time since last loop to dt(minuscule time) and restart the clock
        Time dt = clock.restart();
        input(timer.getElapsedTime());
        update(dt, timer.getElapsedTime());
        draw();
    }
}

void Engine::gameOver()
{
    //nothing yet
}




