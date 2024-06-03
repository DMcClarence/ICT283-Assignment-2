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

#include "../../includes/WeatherMenu/WeatherMenu.h"
#include "../../includes/WeatherRec/WeatherRecIO.h"
#include "../../includes/Vector/VectorUtilities.h"
#include "../../includes/WeatherRec/WeatherRecUtilities.h"
#include "../../includes/Map/Map.h"
// #include "../../includes/Stack/Stack.h"
#include "../../includes/BST/BST.h"

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
    Map<int, Map<int, Vector<int>>> weatherMap; // Outer map key is year, inner map key is month.
    BST<int> yearMonthBST;

    readSuccessful = WeatherRecIO::GetDataFileNameFromSrcFile(fileStack);
    if(readSuccessful)
    {
        fileSuccess = WeatherRecIO::ReadWeatherDataFromFiles(fileStack, weatherLog, weatherMap, yearMonthBST);
    }

    if(fileSuccess)
    {
        // Checks weatherLog isn't empty before running Weather Menu
        if(weatherLog.GetSize() > 0)
        {
            WeatherMenu::RunWeatherMenu(weatherLog, weatherMap, yearMonthBST);
        }
    }

    std::cout << "Program Exiting..." << std::endl;

    return 0;
}

//----------------------------------------------------------------------------
