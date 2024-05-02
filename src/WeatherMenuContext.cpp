// WeatherMenuContext.cpp
//
// Implementation of WeatherMenuContext Class
//
// Version
// 01 18/04/2024 34085068
//      Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "../includes/WeatherMenuContext.h"
//#include <functional>

//----------------------------------------------------------------------------
// Global variables/defines

//----------------------------------------------------------------------------
// Implementation Helper Function Prototypes

//----------------------------------------------------------------------------
// Function implementations

WeatherMenuContext::WeatherMenuContext()
{
}

//----------------------------------------------------------------------------
bool WeatherMenuContext::SetWeatherMenuStrategy(std::function<void(WeatherLogType&)> option)
{
    try
    {
        m_menuOption = option;
    }
    catch(...)
    {
        return false;
    }

    return true;
}

//----------------------------------------------------------------------------
bool WeatherMenuContext::ExecuteWeatherMenuOption(WeatherLogType &weatherLog)
{
    try
    {
        m_menuOption(weatherLog);
    }
    catch(std::bad_function_call& bfc)
    {
        return false;
    }

    return true;
}

//----------------------------------------------------------------------------
