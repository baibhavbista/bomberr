#pragma once
#include "Bomber.h"
#include "LevelMaker.h"
#include "Bomb.h"

class Engine
{
private:

    //main program window
    RenderWindow m_Window;

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

    LevelMaker* m_plevel;
    std::vector<Breakeable>* m_pvBlocksBreakable;

    //Pointer to a bomber
    Bomber* m_PBomber;
    Bomber* m_PBomber0;

    //input, update and draw functions that are called by public member function Engine::start()
    int input(Time t);
    void update(Time dt, Time t);
    void draw();

public:

    //std::vector<Breakeable>* pVBlocksBreakable;

    Engine(std::vector<Bomb>* pm_vBombs);

    //runs game loop , calls input, update, draw within the loop
    void start();
};
