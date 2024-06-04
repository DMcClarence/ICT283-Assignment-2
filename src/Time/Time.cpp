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
}

//----------------------------------------------------------------------------
Time::Time(int hrs, int mins)
{
    m_hours = hrs % 24;
    m_minutes = mins % 60;
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
bool Time::operator==(Time &right) const
{
    if((m_hours == right.m_hours) && (m_minutes == right.m_minutes))
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
