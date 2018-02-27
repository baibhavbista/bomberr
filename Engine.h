
#include "Level.h"
#include "PausableTimer.h"
#include "Bomb.h"
#include "Bomber.h"
#include "RCintoCoor.h"
#include <tuple>
#include <string>

class Engine
{
private:

    //bool that stores condition of program. True if paused
    bool m_gamePaused;

    //bool that stores condition of program. True if game over
    bool m_gameOver;
    //int that stores info about game over condition
    //0 if draw, 1 if Player 1 won, 2 if player 2 won
    int m_gameOverCode;

    //main program window
    RenderWindow& m_Window;

    //Vector of vector of ints that stores level information(position of breakeable, unbreakeable blocks) (taken from random .csv file in Levels folder)
    std::vector < std::vector<int> > Level;

    //Vector of tuples(Beginning Time of explosion, an int which corresponds to which animation to show, Position of cell(row, column))
    std::vector< std::tuple<Time, int, Vector2i> > explosionHelper;

    //Pausable timer for use in countdown clock
    PausableTimer displayTimer;

    //clock for explosion manipulation
    Clock clock_explo;

    //Text and Font objects for countdown timer in Heads Up Display(HUD)
    Text timeDisplayText;
    Font timeDisplayFont;

    //Text and Font objects for lives left for players in Heads Up Display(HUD)
    Text player0LifeText;
    Text player1LifeText;
    Font playerLifeFont;

    //textures for the background, players,(.png found inside backgrounds and sprites folders)
    Texture m_BackgroundTexture;
    Texture m_HUDTexture;
    Texture m_BackgroundPauseTexture;
    Texture m_BackgroundPlayer1Wins;
    Texture m_BackgroundPlayer2Wins;
    Texture m_BackgroundDraw;
    Texture m_FrameTexture;
    Texture m_BlockTexture;
    Texture m_SolidBlockTexture;
    Texture m_PlayerTexture;
    Texture m_BombTexture;
    Texture m_PowerTexture5;
    Texture m_PowerTexture6;
    Texture m_PowerTexture7;
    Texture m_ExplosionTexture;

    //normal sprite for Background
    Sprite m_BackgroundSprite;
    Sprite m_HUDSprite;
    Sprite m_PauseSprite;
    Sprite m_GameOverSprite[3];
    Sprite m_FrameSprite;
    Sprite m_BlockSprite;
    Sprite m_SolidBlockSprite;
    Sprite m_PowerSprite5;
    Sprite m_PowerSprite6;
    Sprite m_PowerSprite7;

    //pointer to array of sprites for explosion
    Sprite* m_ExplosionSprite;

    //Vector of bombs planted and its pointer
    std::vector<Bomb> m_vBombs;
    std::vector<Bomb>* m_pvBombs;


    //Pointer to bombers
    //m_PBomber0 points to player 1, m_PBomber to player 2
    //confusing naming because of the position in the spritesheet and future expansion to different colors
    Bomber* m_PBomber0;
    Bomber* m_PBomber;

    //event object
    Event event;

    //input function called by public member function Engine::start()
    //does input handling for 3 conditions, game screen, pause screen, and win screen
    void input(Time t, Clock timer);

    //update function called by public member function Engine::start()
    //does updating of the sprites according to the condition, runs in game screen only
    void update(Time dt, Time t);

    //draw function called by public member function Engine::start()
    //draws everything out on the screen, for 3 conditions, game screen, pause screen, and win screen
    void draw();

    //called from within Engine::update()
    //enables player to pick up PowerUps
    void PowerupCheck(Bomber* m_PBomber);

    //called from within Engine::update(), updates the HUD
    void updateHUD();

    //function for resuming game, sets private bool m_gamePaused to false
    void resume();

    //function for pausing game, sets private bool m_gamePaused to true
    void pause();

    //function for finishing game after either player wins or time finishes
    //the value of int loser corresponds to state
    //0-draw, 1-player1 lost, 2-player2 lost
    void gameOver(int loser);


public:

    //constructor for the engine class, initializes all the required variables
    Engine(RenderWindow& window);

    //runs game loop , calls input, update, draw within the loop
    void start();

    friend class Bomber;
    friend class Bomb;
    friend class Explosion;

};
