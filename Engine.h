
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

    bool m_gamePaused;
    bool m_gameOver;
    int m_gameOverCode;
    //main program window
    RenderWindow& m_Window;

    std::vector < std::vector<int> > Level;

    std::vector< std::tuple<Time, int, Vector2i> > explosionHelper;
     //LevelMaker m_level;
    PausableTimer displayTimer;
    Clock clock_explo;
    //textures for the background, players,(.png found inside backgrounds and sprites folders)
    Texture m_BackgroundTexture;
    Texture m_BackgroundPauseTexture;
    Texture m_BackgroundPlayer1Wins;
    Texture m_BackgroundPlayer2Wins;
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
    Sprite m_PauseSprite;
    Sprite m_GameOverSprite[3];
    Sprite m_FrameSprite;
    Sprite m_BlockSprite;
    Sprite m_SolidBlockSprite;
    Sprite m_PowerSprite5;
    Sprite m_PowerSprite6;
    Sprite m_PowerSprite7;

    Sprite* m_ExplosionSprite;

    std::vector<Bomb>* m_pvBombs;
    std::vector<Bomb> m_vBombs;

    //LevelMaker* m_plevel;
    //std::vector<Breakeable>* m_pvBlocksBreakable;

    //Pointer to a bomber
    Bomber* m_PBomber;
    Bomber* m_PBomber0;


    Event event;

    //input, update and draw functions that are called by public member function Engine::start()
    void input(Time t);
    void update(Time dt, Time t);
    void draw();

    void PowerupCheck(Bomber* m_PBomber);

    void resume();
    void pause();
    int gameOver(int loser);





public:
    Engine(RenderWindow& window);
    friend class Bomber;
    friend class Bomb;
    friend class Explosion;
    //runs game loop , calls input, update, draw within the loop
    void start();
};
