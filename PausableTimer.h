#include "SFML/Graphics.hpp"

class PausableTimer
{
public:
    sf::Clock m_C;
    float m_runTime;
    bool m_bPaused;

    PausableTimer();
    void Reset();
    void Start();
    void Pause();
    float GetElapsedSeconds();
};

