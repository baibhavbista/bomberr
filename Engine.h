
#include "Level.h"
#include "Bomb.h"
#include "Bomber.h"
#include "RCintoCoor.h"
#include <tuple>

class Engine
{
private:

    //main program window
    RenderWindow m_Window;

    std::vector < std::vector<int> > Level;

    std::tuple<Time, int, Vector2f> explosionHelper;
     //LevelMaker m_level;

    Clock clock;
    //textures for the background, players,(.png found inside backgrounds and sprites folders)
    Texture m_BackgroundTexture;
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
    Sprite m_FrameSprite;
    Sprite m_BlockSprite;
    Sprite m_SolidBlockSprite;
    Sprite m_PowerSprite5;
    Sprite m_PowerSprite6;
    Sprite m_PowerSprite7;

    Sprite m_ExplosionSpriteStart;
    Sprite m_ExplosionSpriteY;
    Sprite m_ExplosionSpriteX;

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
public:


    Engine();
    friend class Bomber;
    friend class Bomb;
    friend class Explosion;
    //runs game loop , calls input, update, draw within the loop
    void start();
    void gameOver();
};
