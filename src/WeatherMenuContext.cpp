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

//----------------------------------------------------------------------------
// Global variables/defines

//----------------------------------------------------------------------------
// Implementation Helper Function Prototypes

//----------------------------------------------------------------------------
// Function implementations

WeatherMenuContext::WeatherMenuContext()
{
    m_menuOption = nullptr;
}

//----------------------------------------------------------------------------
WeatherMenuContext::~WeatherMenuContext()
{
    m_menuOption = nullptr;
}

//----------------------------------------------------------------------------
bool WeatherMenuContext::SetWeatherMenuStrategy(WeatherMenuStrategy *option)
{
    m_menuOption = option;

    if(m_menuOption == nullptr)
    {
        return false;
    }

    return true;
}

//----------------------------------------------------------------------------
bool WeatherMenuContext::ExecuteWeatherMenuOption(WeatherLogType &weatherLog)
{
    if(m_menuOption != nullptr)
    {
        m_menuOption->Execute(weatherLog);
        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
