

#include "Level.h"
#include "Bomb.h"
#include "Bomber.h"
#include "RCintoCoor.h"

class Engine
{
private:

    //main program window
    RenderWindow m_Window;

    std::vector < std::vector<int> > Level;
     //LevelMaker m_level;

    //textures for the background, players,(.png found inside backgrounds and sprites folders)
    Texture m_BackgroundTexture;
    Texture m_FrameTexture;
    Texture m_BlockTexture;
    Texture m_PlayerTexture;
    Texture m_BombTexture;

    //normal sprite for Background
    Sprite m_BackgroundSprite;
    Sprite m_FrameSprite;
    Sprite m_BlockSprite;

    std::vector<Bomb>* m_pvBombs;
    std::vector<Bomb> m_vBombs;

    //LevelMaker* m_plevel;
    //std::vector<Breakeable>* m_pvBlocksBreakable;

    //Pointer to a bomber
    Bomber* m_PBomber;
    Bomber* m_PBomber0;

    bool bombWasPressed[2];

    Event event;

    //input, update and draw functions that are called by public member function Engine::start()
    void input(Time t);
    void update(Time dt, Time t);
    void draw();

public:


    Engine();

    //runs game loop , calls input, update, draw within the loop
    void start();
};
