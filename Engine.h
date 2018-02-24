#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bomber.h"
#include "AnimatedSprite.hpp"
#include "Animation.hpp"

class Engine
{
private:
    RenderWindow m_Window;
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;
    Texture m_PlayerTexture;
    Bomber* m_PBomber;
    void input();
    void update(Time dt);
    void draw();
    Animation walkingAnimationUp, walkingAnimationDown, walkingAnimationLeft, walkingAnimationRight;
    Animation* currentAnimation;

public:
    Engine();

    void start();
};
