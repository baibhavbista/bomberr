#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
Engine::Engine()
{
    //Vector2f resolution;
    //resolution.x = VideoMode::getDesktopMode().width;
    //resolution.y = VideoMode::getDesktopMode().height;
    m_Window.create(VideoMode(500,500), "Bomber Move");
    m_BackgroundTexture.loadFromFile("back.png");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);

    m_PlayerTexture.loadFromFile("bomber1.png");

    float x = 768/12, y = 384/6;
    m_PBomber = new Bomber(m_PlayerTexture, IntRect(0, 0, x, y));
}

void Engine::start()
{
    Clock clock;
    Event event;
    while(m_Window.isOpen())
    {
        while(m_Window.pollEvent(event)){
            if(event.type==Event::Closed){
                m_Window.close();
            }

        }
        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();
        input();
        update(dtAsSeconds);
        draw();
    }
}




