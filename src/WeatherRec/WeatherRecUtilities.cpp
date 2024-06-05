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

#include "../../includes/Vector/VectorUtilities.h"
#include "../../includes/WeatherRec/WeatherRecUtilities.h"

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

Vector<float> WeatherRecUtilities::ExtractValuesFromWeatherLog(WeatherLogType &weatherLog, int month, int year, float WeatherRecType::*p_member)
{
    Vector<float> extractedValues;

    for(int i = 0; i < weatherLog.GetSize(); i++)
    {
        if(weatherLog[i].m_date.GetMonth() == month && weatherLog[i].m_date.GetYear() == year)
        {
            extractedValues.PushBack(weatherLog[i].*p_member);
        }
    }

    return extractedValues;
}

//---------------------------------------------------------------------------------
Vector<float> WeatherRecUtilities::ExtractValuesFromWeatherLog(WeatherLogType &weatherLog, float WeatherRecType::*p_member)
{
    Vector<float> extractedValues;

    for(int i = 0; i < weatherLog.GetSize(); i++)
    {
        extractedValues.PushBack(weatherLog[i].*p_member);
    }

    return extractedValues;
}

//---------------------------------------------------------------------------------
Vector<float>& WeatherRecUtilities::RemoveInvalidData(Vector<float> &data)
{
    for(int i = data.GetSize() - 1; i >= 0; i--)
    {
        if(std::isnan(data[i]))
        {
            VectorUtilities::RemoveFromVector(data, i);
        }
    }

    return data;
}

//---------------------------------------------------------------------------------
std::pair<Vector<float>, Vector<float>>& WeatherRecUtilities::RemoveInvalidDataFromDataPairs(std::pair<Vector<float>, Vector<float>>& data)
{
    if(data.first.GetSize() != data.second.GetSize())
    {
        throw std::invalid_argument("Specified Vectors can't be a pair.");
    }

    for(int i = data.first.GetSize() - 1; i >= 0; i--)
    {
        if(std::isnan(data.first[i]) || std::isnan(data.second[i]))
        {
            VectorUtilities::RemoveFromVector(data.first, i);
            VectorUtilities::RemoveFromVector(data.second, i);
        }
    }
}

//---------------------------------------------------------------------------------
std::string WeatherRecUtilities::MonthToString(int month)
{
    if(month < 1 || month > 12)
    {
        throw std::invalid_argument("Month must be between 1 and 12");
    }
    return months[month - 1];
}

//---------------------------------------------------------------------------------
float& WeatherRecUtilities::ToKMperHr(float &speed)
{
    return speed *= 3.6;
}

//---------------------------------------------------------------------------------
float& WeatherRecUtilities::TokWh(float &solarRad)
{
    solarRad *= (1.0 / 6.0);
    solarRad /= 1000;

    return solarRad;
}

//----------------------------------------------------------------------------
bool operator==(const WeatherRecType &left, const WeatherRecType &right)
{
    if((left.m_date == right.m_date) && (left.m_time == right.m_time))
    {
        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
bool operator!=(const WeatherRecType &left, const WeatherRecType &right)
{
    if((left.m_date != right.m_date) || (left.m_time != right.m_time))
    {
        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
bool operator<(const WeatherRecType &left, const WeatherRecType &right)
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
bool operator<=(const WeatherRecType &left, const WeatherRecType &right)
{
    if((left < right) || (left == right))
    {
        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
bool operator>(const WeatherRecType &left, const WeatherRecType &right)
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
bool operator>=(const WeatherRecType &left, const WeatherRecType &right)
{
    if((left > right) || (left == right))
    {
        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
void WeatherRecUtilities::RemoveDuplicatesFromWeatherLog(WeatherLogType &log)
{
    VectorUtilities::MergeSortVector(log);

    int i = 0;
    while(i < log.GetSize() - 1)
    {
        if(log[i] == log[i + 1])
        {
            VectorUtilities::RemoveFromVector(log, i + 1);
        }
        else
        {
            i++;
        }
    }
}

//----------------------------------------------------------------------------
int WeatherRecUtilities::CreateMonthYearKey(int year, int month)
{
    return (year * 100) + month;
}

//----------------------------------------------------------------------------
