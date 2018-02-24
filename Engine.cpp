#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
Engine::Engine()
{
    //Vector2f resolution;
    //resolution.x = VideoMode::getDesktopMode().width;
    //resolution.y = VideoMode::getDesktopMode().height;
    m_Window.create(VideoMode(448, 336), "Bomber Move");
    m_BackgroundTexture.loadFromFile("back.png");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);

    m_PlayerTexture.loadFromFile("bomber1.png");

    float x = 768/12, y = 384/6;
    m_PBomber = new Bomber(m_PlayerTexture, IntRect(0, 0, x, y));
}

void Engine::start()
{
    Clock clock;
    while(m_Window.isOpen())
    {
        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();
        input();
        update(dtAsSeconds);
        draw();
    }
}

void Engine::input()
{
    if(Keyboard::isKeyPressed(Keyboard::Escape))
    {
        m_Window.close();
    }
    if(Keyboard::isKeyPressed(Keyboard::Left))
    {
        m_PBomber->moveLeft();
    }
    else
    {
        m_PBomber->stopLeft();
    }
    if(Keyboard::isKeyPressed(Keyboard::Right))
    {
        m_PBomber->moveRight();
    }
    else
    {
        m_PBomber->stopRight();
    }
    if(Keyboard::isKeyPressed(Keyboard::Up))
    {
        m_PBomber->moveUp();
    }
    else
    {
        m_PBomber->stopUp();
    }
    if(Keyboard::isKeyPressed(Keyboard::Down))
    {
        m_PBomber->moveDown();
    }
    else
    {
        m_PBomber->stopDown();
    }
}

void Engine::update(float dtAsSeconds)
{
    m_PBomber->update(dtAsSeconds);
}

void Engine::draw()
{
    m_Window.clear(Color::White);

    //m_Window.draw(m_BackgroundSprite);
    m_Window.draw(m_PBomber->getSprite());
    m_Window.display();
}
