// main.cpp
//
// The main Program
//
// Version
// 01 19/04/2024 34085068
//      Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "../includes/WeatherMenu.h"
#include "../includes/weatherRecIO.h"

#include <iostream>
#include <string>

//----------------------------------------------------------------------------
// Global variables/defines

//----------------------------------------------------------------------------
// Prototypes

//----------------------------------------------------------------------------
// Function implementations

int main()
{
    bool readSuccessful = false;
    std::string dataFileName;
    WeatherLogType weatherLog;

    readSuccessful = GetDataFileNameFromSrcFile(dataFileName);
    if(readSuccessful)
    {
        ReadWeatherDataFromFile(dataFileName, weatherLog);
    }
        // Checks weatherLog isn't empty before running Weather Menu
    if(weatherLog.GetSize() > 0)
    {
        RunWeatherMenu(weatherLog);
    }

    return 0;
}

//----------------------------------------------------------------------------
