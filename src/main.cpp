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
#include "../includes/WeatherRecIO.h"
#include "../includes/VectorUtilities.h"
#include "../includes/WeatherRecUtilities.h"
#include "../includes/Map.h"
// #include "../includes/Stack.h"

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
    Stack<std::string> fileStack;
    WeatherLogType weatherLog;
    bool fileSuccess = false;
    //Map<int, Map<int, Vector<int>>> // Outer map key is year, inner map key is month.


    readSuccessful = GetDataFileNameFromSrcFile(fileStack);
    if(readSuccessful)
    {
        fileSuccess = ReadWeatherDataFromFiles(fileStack, weatherLog);
    }

    if(fileSuccess)
    {
        if(weatherLog.GetSize() > 0)
        {
            // RemoveDuplicatesFromWeatherLog(weatherLog);
            RunWeatherMenu(weatherLog);
        }
    }
        // Checks weatherLog isn't empty before running Weather Menu


    std::cout << "Program Exiting..." << std::endl;

    return 0;
}

//----------------------------------------------------------------------------
