#include "Engine.h"
#include <cstdlib>
#include <sstream>
#include <ctime>
using namespace sf;

//total number of asset sets
const int NUM_ASSETS = 2;
const int NUM_LEVELS = 2;
int random(int maxi)
{
    srand(time(NULL));
    int random1 = rand()%maxi;
    //std::cout << random << std::endl;
    return random1 + 1;
}


Engine::Engine(RenderWindow& window):m_Window(window),Level(11, std::vector<int> (17, 0) )
{
    m_gamePaused = false;
    m_gameOver = false;
    m_gameOverCode = 0;
    //resolution based on size of frame, which is (608, 416).
    m_Window.create(VideoMode(608, 416+65), "Bomber Move");

    //sets framerate to 60 fps
    m_Window.setFramerateLimit(60);

    m_HUDTexture.loadFromFile("sprites/HUD.png");
    m_HUDSprite.setTexture(m_HUDTexture);


    timeDisplayFont.loadFromFile("fonts/time.ttf");

    timeDisplayText.setFont(timeDisplayFont);
    timeDisplayText.setCharacterSize(40);
    timeDisplayText.setFillColor(Color::White);
    timeDisplayText.setPosition(150, 8);


    playerLifeFont.loadFromFile("fonts/bomberman.ttf");

    player0LifeText.setFont(playerLifeFont);
    player0LifeText.setCharacterSize(20);
    player0LifeText.setPosition(40, 10);

    player1LifeText.setFont(playerLifeFont);
    player1LifeText.setCharacterSize(20);
    player1LifeText.setPosition(550, 10);

    std::stringstream ss;
    ss << "Levels/" << random(NUM_LEVELS) << ".csv";
    createLevel(ss.str(), Level);

    //loads background from file
    int num_asset = random(NUM_ASSETS);
    ss.str("");
    ss << "backgrounds/" << num_asset << ".png";

    m_BackgroundTexture.loadFromFile(ss.str());
    m_BackgroundSprite.setTexture(m_BackgroundTexture);

    //frame texture and sprite

    ss.str("");
    ss << "sprites/frames/" << num_asset << ".png";
    m_FrameTexture.loadFromFile(ss.str());
    m_FrameSprite.setTexture(m_FrameTexture);
    m_FrameSprite.setPosition(0, 65);

    ss.str("");
    ss << "sprites/blocks/" << num_asset << ".png";
    m_BlockTexture.loadFromFile(ss.str());
    m_BlockSprite.setTexture(m_BlockTexture);
    m_BlockSprite.setTextureRect(IntRect(0, 0, 32, 32));
    m_SolidBlockSprite.setTexture(m_BlockTexture);
    m_SolidBlockSprite.setTextureRect(IntRect(32, 0, 32, 32));

    m_BackgroundPauseTexture.loadFromFile("backgrounds/Pause.png");
    m_PauseSprite.setTexture(m_BackgroundPauseTexture);

    m_BackgroundPlayer1Wins.loadFromFile("backgrounds/player1wins.png");
    m_GameOverSprite[1].setTexture(m_BackgroundPlayer1Wins);

    m_BackgroundPlayer2Wins.loadFromFile("backgrounds/player2wins.png");
    m_GameOverSprite[2].setTexture(m_BackgroundPlayer2Wins);

    m_PowerTexture5.loadFromFile("sprites/powerups/5.png");
    m_PowerSprite5.setTexture(m_PowerTexture5);

    m_PowerTexture6.loadFromFile("sprites/powerups/6.png");
    m_PowerSprite6.setTexture(m_PowerTexture6);

    m_PowerTexture7.loadFromFile("sprites/powerups/7.png");
    m_PowerSprite7.setTexture(m_PowerTexture7);

    m_ExplosionTexture.loadFromFile("sprites/explosion.png");

    m_ExplosionSprite = new Sprite[7];
    for(int i = 0; i < 7; i++)
    {
        m_ExplosionSprite[i].setTexture(m_ExplosionTexture);
        m_ExplosionSprite[i].setTextureRect(IntRect(32*i, 0, 32, 32));
    }


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
    displayTimer.Pause();
    displayTimer.Start();
    while(m_Window.isOpen())
    {
        //std::cout << timer.getElapsedTime().asSeconds() << std::endl;

        //save elapsed time since last loop to dt(minuscule time) and restart the clock
        Time dt = clock.restart();

        if(m_gamePaused)
        {
            displayTimer.Pause();
            input(timer.getElapsedTime());
        }
        else
        {
            displayTimer.Start();
            input(timer.getElapsedTime());
            update(dt, timer.getElapsedTime());
        }
        draw();
    }
}


void Engine::pause()
{
    m_gamePaused = true;
}

void Engine::resume()
{
    m_gamePaused = false;
}

int Engine::gameOver(int loser)
{
    m_gamePaused = true;
    m_gameOver = true;
    m_gameOverCode = (loser==1)?2:1;
}




