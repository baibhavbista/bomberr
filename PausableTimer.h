#include "SFML/Graphics.hpp"

//user defined class that has a sf::Clock as well as a pause and resume mechanism
class PausableTimer
{
public:
    sf::Clock m_C;
    float m_runTime;
    bool m_bPaused;

    //constructor for the pausable timer
    PausableTimer();

    //Resets the pausable timer
    void Reset();

    //Starts/Resumes the pausable timer
    void Start();

    //Pauses the pausable timer
    void Pause();

    //returns the elapsed time in seconds(type float)
    float GetElapsedSeconds();
};

