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

    readSuccessful = GetDataFileNameFromSrcFile(fileStack);
    if(readSuccessful)
    {
        while(!fileStack.IsEmpty())
        {
            std::string fileName;
            fileStack.Pop(fileName);
            ReadWeatherDataFromFile(fileName, weatherLog);
        }
    }

    std::cout << weatherLog.GetSize() << std::endl;
        // Checks weatherLog isn't empty before running Weather Menu
    if(weatherLog.GetSize() > 0)
    {
        RemoveDuplicatesFromWeatherLog(weatherLog);
        RunWeatherMenu(weatherLog);
    }

    std::cout << weatherLog.GetSize() << std::endl;

    return 0;
}

//----------------------------------------------------------------------------
