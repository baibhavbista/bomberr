#include "Engine.h"
using namespace sf;

Engine::Engine()
{
    /*FULLSCREEN
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    std::cout << resolution.x << "\t" << resolution.y <<std::endl;
    */

    //For now, limited to 1366 by 768.
    m_Window.create(VideoMode(640, 448), "Bomber Move");

    //sets framerate to 60 fps
    m_Window.setFramerateLimit(60);

    //loads background from file
    //TODO: random background
    m_BackgroundTexture.loadFromFile("backgrounds/back.png");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);

    //block textures
    m_BlockTexture.loadFromFile("sprites/blocks.png");
    immovable_block.setTexture(m_BlockTexture);
    immovable_block.setTextureRect(IntRect(0, 0, 32, 32));
    immovable_block.setScale(1.5, 1.5);
    immovable_block.setPosition(Vector2f(-10,0));

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
    while(m_Window.isOpen())
    {
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




