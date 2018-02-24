#include "Engine.h"

//function that is called in every game loop, from Engine::start()
//draws all the things
void Engine::draw()
{
    //clear white window
    m_Window.clear(Color::White);

    //draw background
    m_Window.draw(m_BackgroundSprite);

    //draw player 0, upscaled 1.2
    AnimatedSprite dispSprite = (m_PBomber0->getSprite());
    //dispSprite.setScale(1.2, 1.2);

    m_Window.draw(dispSprite);

    //draw player 1, upscaled 1.2
    dispSprite = (m_PBomber->getSprite());
    //dispSprite.setScale(1.2, 1.2);
    m_Window.draw(dispSprite);

    m_Window.draw(immovable_block);
    //display the window
    m_Window.display();
}
