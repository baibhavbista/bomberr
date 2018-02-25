#include "Engine.h"
using namespace sf;

Engine::Engine()
{
    //resolution based on size of frame, which is (608, 416).
    m_Window.create(VideoMode(608, 416+65), "Bomber Move");

    //sets framerate to 60 fps
    m_Window.setFramerateLimit(60);

    //loads background from file
    //TODO: random background
    m_BackgroundTexture.loadFromFile("backgrounds/back.png");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);

    m_BlockTexture.loadFromFile("Sprites/breakable.png");
    m_BlockSprite.setTexture(m_BlockTexture);
    //frame texture and sprite
    if(m_FrameTexture.loadFromFile("sprites/frame.png"))
        std::cout << "Successful" <<std::endl;

    m_FrameSprite.setTexture(m_FrameTexture);
    m_FrameSprite.setPosition(0, 65);

    m_plevel = new LevelMaker();

    m_pvBlocksBreakable = m_plevel->getVBlocksBreakable();
    //block textures

    //Players texture loaded
    m_PlayerTexture.loadFromFile("sprites/player.png");

    //Vector that represents sprite dimensions in sprite sheet (for players/bombers)
    Vector2f spriteDim(768/12, 384/6);
    m_PBomber = new Bomber(m_PlayerTexture, spriteDim, 1);
    m_PBomber0 = new Bomber(m_PlayerTexture, spriteDim, 0);

}

void Engine::start()
{
    Clock clock;
    Event event;
    Vector2f prev(768/12, 384/6);
    Clock timer;
    while(m_Window.isOpen())
    {
        //std::cout << timer.getElapsedTime().asSeconds() << std::endl;
        while(m_Window.pollEvent(event))
        {
            //if close button pressed, close
            if(event.type==Event::Closed)
            {
                m_Window.close();
            }
        }
        //save elapsed time since last loop to dt(minuscule time) and restart the clock
        Time dt = clock.restart();
        input();
        update(dt);
        draw();
    }
}




