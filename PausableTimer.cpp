#include "PausableTimer.h"


PausableTimer::PausableTimer()
{
    m_bPaused = false;
    m_runTime = 0;
    m_C.restart();
}

void PausableTimer::Reset()
{
    m_C.restart();
    m_runTime = 0;
    m_bPaused = false;
}

void PausableTimer::Start()
{
    if (m_bPaused)
    {
        m_C.restart();
    }
    m_bPaused = false;
}

void PausableTimer::Pause()
 {
    if (!m_bPaused)
    {
        m_runTime += m_C.getElapsedTime().asSeconds();
    }
    m_bPaused = true;
}

float PausableTimer::GetElapsedSeconds()
{
    if (!m_bPaused)
    {
        return m_runTime + m_C.getElapsedTime().asSeconds();
    }
    return m_runTime;
}
