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
#include "../includes/BST.h"

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
    Map<int, Map<int, Vector<int>>> indexedWeatherLog; // Outer map key is year, inner map key is month.
    BST<int> myBst;

    readSuccessful = GetDataFileNameFromSrcFile(fileStack);
    if(readSuccessful)
    {
        fileSuccess = ReadWeatherDataFromFiles(fileStack, weatherLog, indexedWeatherLog, myBst);
    }

    if(fileSuccess)
    {
        // Checks weatherLog isn't empty before running Weather Menu
        if(weatherLog.GetSize() > 0)
        {
            // RemoveDuplicatesFromWeatherLog(weatherLog);
            RunWeatherMenu(weatherLog, indexedWeatherLog, myBst);
        }
    }

    std::cout << "Program Exiting..." << std::endl;

    return 0;
}

//----------------------------------------------------------------------------
