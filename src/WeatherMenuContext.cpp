// WeatherMenuContext.cpp
//
// Implementation of WeatherMenuContext Class
//
// Version
// 01 18/04/2024 34085068
//      Started
// 02 01/05/2024 34085068
//      Modify to pass functions instead of objects
// 03 14/05/2024 34085068
//      Modify to use function pointers instead of std::function
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
}

//----------------------------------------------------------------------------
bool WeatherMenuContext::SetWeatherMenuStrategy(void (*menuOption)(WeatherLogType&, std::map<int, std::map<int, Vector<int>>>&, BST<KeyValue<int, WeatherRecType>>&))
{
    try
    {
        m_menuOption = menuOption;
    }
    catch(...)
    {
        return false;
    }

    return true;
}

//----------------------------------------------------------------------------
bool WeatherMenuContext::ExecuteWeatherMenuOption(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst)
{
    try
    {
        m_menuOption(weatherLog, myMap, myBst);
    }
    catch(...)
    {
        return false;
    }

    return true;
}

//----------------------------------------------------------------------------
