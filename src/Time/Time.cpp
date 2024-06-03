// Time.cpp
//
// Time class implementation
//
// Version
// 01 08/04/2024 34085068
//      Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "../../includes/Time/Time.h"

//----------------------------------------------------------------------------
// Global variables/defines

//----------------------------------------------------------------------------
// Prototypes

//----------------------------------------------------------------------------
// Function implementations

Time::Time()
{
        // Default time Values
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;
}

//----------------------------------------------------------------------------
Time::Time(int hrs, int mins, int secs)
{
    m_hours = hrs % 24;
    m_minutes = mins % 60;
    m_seconds = secs % 60;
}

//----------------------------------------------------------------------------
int Time::GetHours() const
{
    return m_hours;
}

//----------------------------------------------------------------------------
int Time::GetMinutes() const
{
    return m_minutes;
}

//----------------------------------------------------------------------------
int Time::GetSeconds() const
{
    return m_seconds;
}

//----------------------------------------------------------------------------
void Time::SetHours(int hrs)
{
    m_hours = hrs % 24;
}

//----------------------------------------------------------------------------
void Time::SetMinutes(int mins)
{
    m_minutes = mins % 60;
}

//----------------------------------------------------------------------------
void Time::SetSeconds(int secs)
{
    m_seconds = secs % 60;
}

//----------------------------------------------------------------------------
bool Time::operator==(Time &right) const
{
    if((m_hours == right.m_hours) && (m_minutes == right.m_minutes) && (m_seconds == right.m_seconds))
    {
        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
bool Time::operator<(Time &right) const
{
    bool isLessThan = false;

    if(m_hours < right.m_hours)
    {
        isLessThan = true;
    }

    if(m_hours == right.m_hours)
    {
        if(m_minutes < right.m_minutes)
        {
            isLessThan = true;
        }

        if(m_minutes == right.m_minutes)
        {
            if(m_seconds < right.m_seconds)
            {
                isLessThan = true;
            }
        }
    }

    return isLessThan;
}

//----------------------------------------------------------------------------
bool Time::operator<=(Time &right) const
{
    if((*this < right) || (*this == right))
    {
        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
bool Time::operator>(Time &right) const
{
    bool isGreaterThan = false;

    if(m_hours > right.m_hours)
    {
        isGreaterThan = true;
    }

    if(m_hours == right.m_hours)
    {
        if(m_minutes > right.m_minutes)
        {
            isGreaterThan = true;
        }

        if(m_minutes == right.m_minutes)
        {
            if(m_seconds > right.m_seconds)
            {
                isGreaterThan = true;
            }
        }
    }

    return isGreaterThan;
}

//----------------------------------------------------------------------------
bool Time::operator>=(Time &right) const
{
    if((*this > right) || (*this == right))
    {
        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
bool Time::operator!=(Time &right) const
{
    if(*this == right)
    {
        return false;
    }

    return true;
}

//----------------------------------------------------------------------------
