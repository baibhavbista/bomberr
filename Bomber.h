
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"

#include "AnimatedSprite.hpp"
#include "Animation.hpp"
using namespace sf;

class Bomber
{
private:

    //this vector holds the x and y position of the sprite
    Vector2f m_Position;

    AnimatedSprite m_Sprite;

    //booleans that are set when have to move in a certain direction
    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_UpPressed;
    bool m_DownPressed;

    //speed of the bomber in pixels/sec
    float m_Speed;

    //Texture pointer for the bomber
    Texture& m_TextureBomber;

    //animations for the movement
    Animation walkingAnimationDown, walkingAnimationUp, walkingAnimationLeft, walkingAnimationRight;

    //animation current movement
    Animation* currentAnimation;

public:

    //Color of the bomber. 0 White, 1 Black, 2 Blue, 3 Red
    int m_color;

    Bomber(Texture& texture_bomber, Vector2f spriteDim, int color);

    //returns the sprite
    //called by Engine::draw() to draw on the screen
    AnimatedSprite getSprite();

    //returns true if no key(movement key) is pressed. Used in update function above to stop
    bool noKeyPressed();

    //function that updates m_Sprite(animation, position, continue or stop, etc)
    void update(Time dt);

    //functions to select animation and set and reset the boolean variables defined above like m_LeftPressed
    void moveLeft();
    void stopLeft();
    void moveRight();
    void stopRight();
    void moveUp();
    void stopUp();
    void moveDown();
    void stopDown();
};
