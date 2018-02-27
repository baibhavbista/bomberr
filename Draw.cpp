#include "Engine.h"
#include "Bomb.h"
#include "Bomber.h"
//function that is called in every game loop, from Engine::start()
//draws all the things
void Engine::draw()
{
    //clear white window
    m_Window.clear(Color::White);


    if(m_gameOver)
    {
        m_Window.draw(m_GameOverSprite[m_gameOverCode]);
    }
    else if(m_gamePaused)
    {
        m_Window.draw(m_PauseSprite);
    }
    else
    {
        //draw background
        m_Window.draw(m_BackgroundSprite);
        m_Window.draw(m_FrameSprite);

        Vector2f coor_tr;
        for(int r = 0; r < 11; r++)
        {
            for(int c = 0; c < 17; c++)
            {
                if((Level)[r][c] == 1)
                {
                    coor_tr = rcIntoCoor(r,c);
                    m_BlockSprite.setPosition(coor_tr);
                    m_Window.draw(m_BlockSprite);
                }
                else if((Level)[r][c] == 2)
                {
                    coor_tr = rcIntoCoor(r,c);
                    m_SolidBlockSprite.setPosition(coor_tr);
                    m_Window.draw(m_SolidBlockSprite);
                }
                else if((Level)[r][c] == 4)
                {
                    coor_tr = rcIntoCoor(r,c);
                    Sprite bomb(m_BombTexture, IntRect(0, 0, 32, 32));
                    bomb.setPosition(coor_tr);
                    m_Window.draw(bomb);
                }
                else if((Level)[r][c] == 5)
                {
                    coor_tr = rcIntoCoor(r,c);
                    m_PowerSprite5.setPosition(coor_tr);
                    m_Window.draw(m_PowerSprite5);
                }
                else if((Level)[r][c] == 6)
                {
                    coor_tr = rcIntoCoor(r,c);
                    m_PowerSprite6.setPosition(coor_tr);
                    m_Window.draw(m_PowerSprite6);
                }
                else if((Level)[r][c] == 7)
                {
                    coor_tr = rcIntoCoor(r,c);
                    m_PowerSprite7.setPosition(coor_tr);
                    m_Window.draw(m_PowerSprite7);
                }
            }
        }
        std::vector<Sprite> explosionSprites;
        //(m_pEngine->explosionHelper).push_back(std::make_tuple((m_pEngine->clock.getElapsedTime()), num, startCell));
        for(auto tup:explosionHelper)
        {
            if((clock_explo).getElapsedTime().asSeconds() - std::get<0>(tup).asSeconds() <= 1)
            {
                //std::cout << std::get<0>(tup).asSeconds() << " " << std::get<1>(tup) << " (" << std::get<2>(tup).x << ", " <<std::get<2>(tup).y << ")" << std::endl;
                Sprite temp = m_ExplosionSprite[std::get<1>(tup)-1];
                //std::cout << (clock_explo).getElapsedTime().asSeconds() << std::get<2>(tup).x << " " << std::get<2>(tup).y << std::endl;
                Vector2f coor = rcIntoCoor(std::get<2>(tup).x, std::get<2>(tup).y);

                Vector2i bomberCell = m_PBomber->getRCVector();
                if(bomberCell.x==std::get<2>(tup).x && bomberCell.y == std::get<2>(tup).y)
                {
                    m_PBomber->die();
                }
                bomberCell = m_PBomber0->getRCVector();
                if(bomberCell.x==std::get<2>(tup).x && bomberCell.y == std::get<2>(tup).y)
                {
                    m_PBomber0->die();
                }
                //std::cout << coor.x << " " << coor.y << std::endl;
                temp.setPosition(coor);
                explosionSprites.push_back(temp);
            }
        }
        for(int i = 0; i < explosionSprites.size(); i++)
        {
            m_Window.draw(explosionSprites[i]);
        }


        AnimatedSprite dispSprite;
        for(int i = 0; i < int((*m_pvBombs).size()); i++)
        {
            if(!((*m_pvBombs)[i]).isBlasted())
            {
                dispSprite = (*m_pvBombs)[i].getSprite();
                m_Window.draw(dispSprite);
            }
        }
        //draw player 0, upscaled 1.2
        dispSprite = (m_PBomber0->getSprite());
        //dispSprite.setScale(0.8, 0.8);

        m_Window.draw(dispSprite);

        //draw player 1, upscaled 1.2
        dispSprite = (m_PBomber->getSprite());
        //dispSprite.setScale(0.8, 0.8);
        m_Window.draw(dispSprite);


    }
    //display the window
    m_Window.display();
}
