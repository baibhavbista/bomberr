
#include <SFML/Graphics.hpp>
using namespace sf;

enum direction{DOWN, UP, LEFT, RIGHT=5};

class Bomber
{
private:
    Vector2f m_Position;
    Sprite m_Sprite;
    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_UpPressed;
    bool m_DownPressed;
    float m_Speed;
    Texture& m_TextureBomber;
    IntRect m_RectSourceSprite, m_RectSourceSprite_down;

public:
    Bomber(Texture& texture_bomber, IntRect rectSourceSprite);
    Sprite getSprite();
    void moveLeft();
    void stopLeft();
    void moveRight();
    void stopRight();
    void moveUp();
    void stopUp();
    void moveDown();
    void stopDown();
    void update(float elapsedTime);
};
