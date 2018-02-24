
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include "Animation.hpp"
using namespace sf;

enum direction{DOWN, UP, LEFT, RIGHT=5};

class Bomber
{
private:
    Vector2f m_Position;
    AnimatedSprite m_Sprite;
    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_UpPressed;
    bool m_DownPressed;
    float m_Speed;
    Texture& m_TextureBomber;
    IntRect m_RectSourceSprite, m_RectSourceSprite_down;
    Animation walkingAnimationDown, walkingAnimationUp, walkingAnimationLeft, walkingAnimationRight;
    Animation* currentAnimation;
public:
    Bomber(Texture& texture_bomber, IntRect rectSourceSprite);
    AnimatedSprite getSprite();
    void moveLeft();
    void stopLeft();
    void moveRight();
    void stopRight();
    void moveUp();
    void stopUp();
    void moveDown();
    void stopDown();
    void update(Time dt);
    bool noKeyPressed();
};
