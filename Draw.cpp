#include "Engine.h"
#include "Bomb.h"
#include "Bomber.h"
//function that is called in every game loop, from Engine::start()
//draws all the things
void Engine::draw()
{
    //clear to a white window
    m_Window.clear(Color::White);

    //if game over
    if(m_gameOver)
    {
        m_Window.draw(m_GameOverSprite[m_gameOverCode]);
    }
    //else if game paused
    else if(m_gamePaused)
    {
        m_Window.draw(m_PauseSprite);
    }
    //else(game running)
    else
    {
        //draw background
        m_Window.draw(m_BackgroundSprite);

        //draw Heads Up Display and its components(countdown timer, remaining lives of players)
        m_Window.draw(m_HUDSprite);
        m_Window.draw(timeDisplayText);
        m_Window.draw(player0LifeText);
        m_Window.draw(player1LifeText);

        //draws frame
        m_Window.draw(m_FrameSprite);

        Vector2f coor_tr;

        //check the matrix Levels and draw breakeable blocks(1), unbreakeable blocks(2), bombs(4), powerups(5, 6, 7)
        //iterate over matrix(actually vector of vectors of ints) Level
        for(int r = 0; r < 11; r++)
        {
            for(int c = 0; c < 17; c++)
            {
                //draw breakeable blocks
                if((Level)[r][c] == 1)
                {
                    coor_tr = rcIntoCoor(r,c);
                    m_BlockSprite.setPosition(coor_tr);
                    m_Window.draw(m_BlockSprite);
                }
                //draw unbreakeable blocks
                else if((Level)[r][c] == 2)
                {
                    coor_tr = rcIntoCoor(r,c);
                    m_SolidBlockSprite.setPosition(coor_tr);
                    m_Window.draw(m_SolidBlockSprite);
                }
                //draw bombs
                else if((Level)[r][c] == 4)
                {
                    coor_tr = rcIntoCoor(r,c);
                    Sprite bomb(m_BombTexture, IntRect(0, 0, 32, 32));
                    bomb.setPosition(coor_tr);
                    m_Window.draw(bomb);
                }
                //draw powerups
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

        //the following few blocks of code draw explosions on the screen
        //set up vector of sprites for explosion
        std::vector<Sprite> explosionSprites;

        //setting up the explosions in std::vector<Sprite> explosionSprites
        //for every tuple in Engine::explosionHelper
        for(auto tup:explosionHelper)
        {
            //explosion animation run only
            //if current time is greater than explosion start time by less than 1 s
            //effect is that explosions are seen for 1 s
            if((clock_explo).getElapsedTime().asSeconds() - std::get<0>(tup).asSeconds() <= 1)
            {
                Sprite temp = m_ExplosionSprite[std::get<1>(tup)-1];
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

        //drawing the explosions in std::vector<Sprite> explosionSprites
        for(int i = 0; i < explosionSprites.size(); i++)
        {
            m_Window.draw(explosionSprites[i]);
        }

        //temp AnimatedSprite Variable that holds sprites for bombs and bombers
        AnimatedSprite dispSprite;

        //draws bombs
        for(int i = 0; i < int((*m_pvBombs).size()); i++)
        {
            if(!((*m_pvBombs)[i]).isBlasted())
            {
                dispSprite = (*m_pvBombs)[i].getSprite();
                m_Window.draw(dispSprite);
            }
        }

        //draw player 0
        dispSprite = (m_PBomber0->getSprite());
        m_Window.draw(dispSprite);

        //draw player 1
        dispSprite = (m_PBomber->getSprite());
        m_Window.draw(dispSprite);

    }

    //display the window
    m_Window.display();
}
