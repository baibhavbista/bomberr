
#include "Bomber.h"

class Engine
{
private:

    //main program window
    RenderWindow m_Window;

    //textures for the background, players,(.png found inside backgrounds and sprites folders)
    Texture m_BackgroundTexture;
    Texture m_FrameTexture;
    Texture m_BlockTexture;
    Texture m_PlayerTexture;

    //normal sprite for Background
    Sprite m_BackgroundSprite;
    Sprite m_FrameSprite;
    Sprite immovable_block;

    //Pointer to a bomber
    Bomber* m_PBomber;
    Bomber* m_PBomber0;

    //input, update and draw functions that are called by public member function Engine::start()
    int input();
    void update(Time dt);
    void draw();

public:

    Engine();

    //runs game loop , calls input, update, draw within the loop
    void start();
};
