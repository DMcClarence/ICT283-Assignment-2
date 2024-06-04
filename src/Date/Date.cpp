// Date.cpp
//
// Date class implementation
//
// Version
// 01 21/03/2024 34085068
//      Started
// 02 04/05/2024 34085068
//      Add comparison operator overloads as Dates have a natural order.
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "../../includes/Date/Date.h"

//----------------------------------------------------------------------------
// Global variables/defines

//----------------------------------------------------------------------------
// Implementation Helper Function Prototypes

    // Functions Prototyped here are only used as Helpers for Implementation.
    // Not Designed for client use, hence why they're not prototyped in the interface.

    // Checks to make sure the Day is valid based on the Year and Month of the Object
bool DayIsValid(int d, int m, int y);

    // Checks to see if the month is Valid (1 - 12)
bool MonthIsValid(int m);

    // Checks to see if the year is a Leap Year or Not
bool IsLeapYear(int y);

//----------------------------------------------------------------------------
// Function implementations

Date::Date()
{
        // Default Date Values
        // Done to avoid Date being invalid when constructed.
    m_day = 1;
    m_month = 1;
    m_year = 2000;
}

//----------------------------------------------------------------------------
Date::Date(int d, int m, int y)
{
        // Sets in Order of Year, Month, Day to Accurately Check Validations
        // If invalid, values from default constructor used.
    m_year = y;

    if(MonthIsValid(m))
    {
        m_month = m;
    }

    if(DayIsValid(d, m_month, m_year))
    {
        m_day = d;
    }
}

//----------------------------------------------------------------------------
int Date::GetDay() const
{
    return m_day;
}

//----------------------------------------------------------------------------
int Date::GetMonth() const
{
    return m_month;
}

//----------------------------------------------------------------------------
int Date::GetYear() const
{
    return m_year;
}

//----------------------------------------------------------------------------
bool Date::SetDay(int d)
{
        // Uses Currently Set Month and Year of Object to Check Validation
    if(DayIsValid(d, m_month, m_year))
    {
        m_day = d;
        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
bool Date::SetMonth(int m)
{
    if(MonthIsValid(m))
    {
            // Also Check to make sure day is still valid with month
        if(DayIsValid(m_day, m, m_year))
        {
            m_month = m;
            return true;
        }
    }

    return false;
}

//----------------------------------------------------------------------------
void Date::SetYear(int y)
{
    m_year = y;
}

//----------------------------------------------------------------------------
bool DayIsValid(int d, int m, int y)
{
    bool valid = false;

    if(d > 0)
    {
        if(m == 2)
        {
            if(IsLeapYear(y) && d <= 29)
            {
                valid = true;
            }
            else if(d <= 28)
            {
                valid = true;
            }
        }

        if(m == 4 || m == 6 || m == 9 || m == 11)
        {
            if(d <= 30)
            {
                valid = true;
            }
        }
        else
        {
            if(d <= 31)
            {
                valid = true;
            }
        }
    }

    return valid;
}

//----------------------------------------------------------------------------
bool MonthIsValid(int m)
{
    if(m > 0 && m <= 12)
    {
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
bool IsLeapYear(int y)
{
    bool LeapYear = false;

    if((y % 4) == 0)
    {
        if((y % 100) == 0)
        {
            if((y % 400) == 0)
            {
                LeapYear = true;
            }
        }
        else
        {
            LeapYear = true;
        }
    }

    return LeapYear;
}

//----------------------------------------------------------------------------
bool Date::operator==(const Date &right) const
{
    if((m_day == right.m_day) && (m_month == right.m_month) && (m_year == right.m_year))
    {
        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
bool Date::operator<(const Date &right) const
{
    bool isLessThan = false;

    if(m_year < right.m_year)
    {
        isLessThan = true;
    }

    if(m_year == right.m_year)
    {
        if(m_month < right.m_month)
        {
            isLessThan = true;
        }

        if(m_month == right.m_month)
        {
            if(m_day < right.m_day)
            {
                isLessThan = true;
            }
        }
    }

    return isLessThan;
}

//----------------------------------------------------------------------------
bool Date::operator<=(const Date &right) const
{
    if((*this < right) || (*this == right))
    {
        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
bool Date::operator>(const Date &right) const
{
    bool isGreaterThan = false;

    if(m_year > right.m_year)
    {
        isGreaterThan = true;
    }

    if(m_year == right.m_year)
    {
        if(m_month > right.m_month)
        {
            isGreaterThan = true;
        }

        if(m_month == right.m_month)
        {
            if(m_day > right.m_day)
            {
                isGreaterThan = true;
            }
        }
    }

    return isGreaterThan;
}

//----------------------------------------------------------------------------
bool Date::operator>=(const Date &right) const
{
    if((*this > right) || (*this == right))
    {
        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
bool Date::operator!=(const Date &right) const
{
    if(*this == right)
    {
        return false;
    }

    return true;
}

//----------------------------------------------------------------------------
