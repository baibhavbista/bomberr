#include "PausableTimer.h"

//constructor for the pausable timer
PausableTimer::PausableTimer()
{
    m_bPaused = false;
    m_runTime = 0;
    m_C.restart();
}

//Resets the pausable timer
void PausableTimer::Reset()
{
    m_C.restart();
    m_runTime = 0;
    m_bPaused = false;
}

//Starts/Resumes the pausable timer
void PausableTimer::Start()
{
    if (m_bPaused)
    {
        m_C.restart();
    }
    m_bPaused = false;
}

//Pauses the pausable timer
void PausableTimer::Pause()
 {
    if (!m_bPaused)
    {
        m_runTime += m_C.getElapsedTime().asSeconds();
    }
    m_bPaused = true;
}

//returns the elapsed time in seconds(type float)
float PausableTimer::GetElapsedSeconds()
{
    if (!m_bPaused)
    {
        return m_runTime + m_C.getElapsedTime().asSeconds();
    }
    return m_runTime;
}
