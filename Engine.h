#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bomber.h"

class Engine
{
private:
    RenderWindow m_Window;
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;
    Texture m_PlayerTexture;
    Bomber* m_PBomber;
    void input();
    void update(float dtAsSeconds);
    void draw();

public:
    Engine();

    void start();
};
