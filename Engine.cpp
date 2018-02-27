#include "Engine.h"
#include <cstdlib>
#include <sstream>
#include <ctime>
using namespace sf;

//total number of asset sets
const int NUM_ASSETS = 2;
const int NUM_LEVELS = 2;

//generates random int from 1 to maxi
int random(int maxi)
{
    //seeds the random number generator
    srand(time(NULL));
    int random1 = rand()%maxi;
    return random1 + 1;
}

//constructor for the engine class, initializes all the required variables
Engine::Engine(RenderWindow& window):m_Window(window),Level(11, std::vector<int> (17, 0) )
{
    //sets default values for game state variables
    m_gamePaused = false;
    m_gameOver = false;
    m_gameOverCode = 0;

    //resolution based on size of frame, which is (608, 416).
    m_Window.create(VideoMode(608, 416+65), "Bomber Move");

    //sets framerate to 60 fps
    m_Window.setFramerateLimit(60);

    //Texture and Sprite for Heads Up Display
    m_HUDTexture.loadFromFile("sprites/HUD.png");
    m_HUDSprite.setTexture(m_HUDTexture);

    //Font and Text objects for countdown timer
    timeDisplayFont.loadFromFile("fonts/time.ttf");
    timeDisplayText.setFont(timeDisplayFont);
    timeDisplayText.setCharacterSize(40);
    timeDisplayText.setFillColor(Color::White);
    timeDisplayText.setPosition(150, 8);

    //Font and Text objects for lives left of players
    playerLifeFont.loadFromFile("fonts/bomberman.ttf");

    player0LifeText.setFont(playerLifeFont);
    player0LifeText.setCharacterSize(20);
    player0LifeText.setPosition(40, 10);

    player1LifeText.setFont(playerLifeFont);
    player1LifeText.setCharacterSize(20);
    player1LifeText.setPosition(550, 10);

    //generates random number and selects corresponding level from /Levels/ dir
    //saves info in vector of vector of int "Level"
    std::stringstream ss;
    ss << "Levels/" << random(NUM_LEVELS) << ".csv";
    createLevel(ss.str(), Level);

    //generates random number and selects corresponding background from /backgrounds/ dir
    //background, frame, and blocks use same random variable as they are best when match when each other
    int num_asset = random(NUM_ASSETS);
    ss.str("");
    ss << "backgrounds/" << num_asset << ".png";
    //loads background from file
    m_BackgroundTexture.loadFromFile(ss.str());
    m_BackgroundSprite.setTexture(m_BackgroundTexture);

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


    //Pause Texture and Sprite
    m_BackgroundPauseTexture.loadFromFile("backgrounds/Pause.png");
    m_PauseSprite.setTexture(m_BackgroundPauseTexture);

    //End of Game Screens
    //Draw Screen
    m_BackgroundDraw.loadFromFile("backgrounds/drawscreen.png");
    m_GameOverSprite[0].setTexture(m_BackgroundDraw);

    //Player1 wins screen
    m_BackgroundPlayer1Wins.loadFromFile("backgrounds/player1wins.png");
    m_GameOverSprite[1].setTexture(m_BackgroundPlayer1Wins);

    //Player2 wins screen
    m_BackgroundPlayer2Wins.loadFromFile("backgrounds/player2wins.png");
    m_GameOverSprite[2].setTexture(m_BackgroundPlayer2Wins);


    //Textures and Sprites for powerups
    //are named 5, 6, 7 since that is how they are represented on Level
    m_PowerTexture5.loadFromFile("sprites/powerups/5.png");
    m_PowerSprite5.setTexture(m_PowerTexture5);

    m_PowerTexture6.loadFromFile("sprites/powerups/6.png");
    m_PowerSprite6.setTexture(m_PowerTexture6);

    m_PowerTexture7.loadFromFile("sprites/powerups/7.png");
    m_PowerSprite7.setTexture(m_PowerTexture7);

    //Texture and sprites for explosion
    m_ExplosionTexture.loadFromFile("sprites/explosion.png");
    m_ExplosionSprite = new Sprite[7];
    for(int i = 0; i < 7; i++)
    {
        m_ExplosionSprite[i].setTexture(m_ExplosionTexture);
        m_ExplosionSprite[i].setTextureRect(IntRect(32*i, 0, 32, 32));
    }


    m_pvBombs = &m_vBombs;

    //Loading Players and bombs texture
    m_PlayerTexture.loadFromFile("sprites/player.png");
    m_BombTexture.loadFromFile("sprites/bombs.png");

    //Vector that represents sprite dimensions in sprite sheet (for players i.e.bombers)
    Vector2f spriteDim(768/12, 384/6);

    //Makes two bombers for two player game
    m_PBomber = new Bomber(this, m_PlayerTexture, spriteDim, 1);
    m_PBomber0 = new Bomber(this, m_PlayerTexture, spriteDim, 0);
}

//runs game loop , calls input, update, draw within the loop
void Engine::start()
{
    Clock clock;
    Clock timer;

    //countdown timer pause and start
    displayTimer.Pause();
    displayTimer.Start();

    while(m_Window.isOpen())
    {
        //save elapsed time since last loop to dt(minuscule time) and restart the clock
        Time dt = clock.restart();

        if(m_gamePaused)
        {
            displayTimer.Pause();
            input(timer.getElapsedTime(), timer);
        }
        else
        {
            displayTimer.Start();
            input(timer.getElapsedTime(), timer);
            update(dt, timer.getElapsedTime());
        }
        draw();
    }
}

//function for pausing game, sets private bool m_gamePaused to true
void Engine::pause()
{
    m_gamePaused = true;
}

//function for resuming game, sets private bool m_gamePaused to false
void Engine::resume()
{
    m_gamePaused = false;
}

//function for finishing game after either player wins or time finishes
//the value of int loser corresponds to state
//0-draw, 1-player1 lost, 2-player2 lost
void Engine::gameOver(int loser)
{
    //m_gamePaused = true;
    m_gameOver = true;
    if(loser==0)
        m_gameOverCode = 0;
    else
        m_gameOverCode = (loser==1)?2:1;
}




