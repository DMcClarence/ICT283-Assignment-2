// weatherRecUtilities.cpp
//
// WeatherRecType and WeatherLogType Utility Functions Implementation
//
// Version
// 01 13/04/2024 34085068
//      Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "../includes/VectorUtilities.h"
#include "../includes/WeatherRecUtilities.h"

#include <string>
#include <cmath>
#include <stdexcept>

//----------------------------------------------------------------------------
// Global variables/defines

const std::string months[12] = {"January",
                            "February",
                            "March",
                            "April",
                            "May",
                            "June",
                            "July",
                            "August",
                            "September",
                            "October",
                            "November",
                            "December"};

//----------------------------------------------------------------------------
// Prototypes

//----------------------------------------------------------------------------
// Function implementations

void ExtractValuesFromWeatherLog(WeatherLogType &weatherLog, int month, int year,
                                    float WeatherRecType::*p_member, Vector<float> &extractedValues)
{
    for(int i = 0; i < weatherLog.GetSize(); i++)
    {
        if(weatherLog[i].m_date.GetMonth() == month && weatherLog[i].m_date.GetYear() == year)
        {
            extractedValues.PushBack(weatherLog[i].*p_member);
        }
    }
}

//---------------------------------------------------------------------------------
void ExtractValuesFromWeatherLog(WeatherLogType &weatherLog, float WeatherRecType::*p_member, Vector<float> &extractedValues)
{
    for(int i = 0; i < weatherLog.GetSize(); i++)
    {
        extractedValues.PushBack(weatherLog[i].*p_member);
    }
}

//---------------------------------------------------------------------------------
void RemoveInvalidData(Vector<float> &data)
{
    for(int i = data.GetSize() - 1; i >= 0; i--)
    {
        if(std::isnan(data[i]))
        {
            RemoveFromVector(data, i);
        }
    }
}

//---------------------------------------------------------------------------------
void RemoveInvalidDataFromDataPairs(Vector<float> &data1, Vector<float> &data2)
{
    if(data1.GetSize() != data2.GetSize())
    {
        throw std::invalid_argument("Specified Vectors can't be a pair.");
    }

    for(int i = data1.GetSize() - 1; i >= 0; i--)
    {
        if(std::isnan(data1[i]) || std::isnan(data2[i]))
        {
            RemoveFromVector(data1, i);
            RemoveFromVector(data2, i);
        }
    }
}

//---------------------------------------------------------------------------------
std::string MonthToString(int month)
{
    assert(month > 0 && month <= 12);
    return months[month - 1];
}

//---------------------------------------------------------------------------------
void ToKMperHr(float &speed)
{
    speed *= 3.6;
}

//---------------------------------------------------------------------------------
void TokWh(float &solarRad)
{
    solarRad *= (1.0 / 6.0);
    solarRad /= 1000;
}

//----------------------------------------------------------------------------
bool operator==(WeatherRecType &left, WeatherRecType &right)
{
    if((left.m_date == right.m_date) && (left.m_time == right.m_time))
    {
        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
bool operator<(WeatherRecType &left, WeatherRecType &right)
{
    bool isLessThan = false;

    if(left.m_date < right.m_date)
    {
        isLessThan = true;
    }

    if(left.m_date == right.m_date)
    {
        if(left.m_time < right.m_time)
        {
            isLessThan = true;
        }
    }

    return isLessThan;
}

//----------------------------------------------------------------------------
bool operator<=(WeatherRecType &left, WeatherRecType &right)
{
    if((left < right) || (left == right))
    {
        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
bool operator>(WeatherRecType &left, WeatherRecType &right)
{
    bool isGreaterThan = false;

    if(left.m_date > right.m_date)
    {
        isGreaterThan = true;
    }

    if(left.m_date == right.m_date)
    {
        if(left.m_time > right.m_time)
        {
            isGreaterThan = true;
        }
    }

    return isGreaterThan;
}

//----------------------------------------------------------------------------
bool operator>=(WeatherRecType &left, WeatherRecType &right)
{
    if((left > right) || (left == right))
    {
        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
void RemoveDuplicatesFromWeatherLog(WeatherLogType &log)
{
    MergeSortVector(log);

    int i = 0;
    while(i < log.GetSize() - 1)
    {
        if(log[i] == log[i + 1])
        {
            RemoveFromVector(log, i + 1);
        }
        else
        {
            i++;
        }
    }
}

//----------------------------------------------------------------------------
int CreateMonthYearKey(int year, int month)
{
    return (year * 100) + month;
}

//----------------------------------------------------------------------------
