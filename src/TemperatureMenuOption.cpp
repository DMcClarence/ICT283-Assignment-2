// TemperatureMenuOption.cpp
//
// Implementation of TemperatureMenuOption Class
// Derived from WeatherMenuStrategy Abstract Class
//
// Version
// 01 17/04/2024 34085068
//      Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "../includes/TemperatureMenuOption.h"
#include "../includes/WeatherRecUtilities.h"
#include "../includes/StatsCalcs.h"

#include <iostream>
#include <iomanip>

//----------------------------------------------------------------------------
// Global variables/defines

enum months {Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12};

//----------------------------------------------------------------------------
// Implementation Helper Function Prototypes

    // Functions Prototyped here are only used as Helpers for Implementation.
    // Not Designed for client use, hence why they're not prototyped in the interface.

    // Dedicated to Printing Mean and Standard Deviation of Temperature to the Screen
void PrintTempMeanStdDevToScreen(WeatherLogType &weatherLog, int month, int year);

//----------------------------------------------------------------------------
// Function implementations

TemperatureMenuOption::TemperatureMenuOption()
{
}

//----------------------------------------------------------------------------
void TemperatureMenuOption::Execute(WeatherLogType &weatherLog)
{
    int year;

    std::cout << "Enter a Year: " << std::endl;
    std::cin >> year;
    std::cin.clear();

    std::cout << std::endl;
    std::cout << year << std::endl;
    for(int month = Jan; month <= Dec; month++)
    {
        PrintTempMeanStdDevToScreen(weatherLog, month, year);
    }
    std::cout << std::endl;
}

//----------------------------------------------------------------------------
void PrintTempMeanStdDevToScreen(WeatherLogType &weatherLog, int month, int year)
{
    Vector<float> data;
    ExtractValuesFromWeatherLog(weatherLog, month, year, &WeatherRecType::m_t, data);

    std::cout << MonthToString(month) << ": ";
    if(data.GetSize() == 0)
    {
        std::cout << "No Data" << std::endl;
    }
    else
    {
        float avgTemp = CalcMeanOfVectorf(data);
        float tempStdDev = CalcStdDevOfVectorf(data);
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "average: " << avgTemp << " degrees C, stdev: " << tempStdDev << std::endl;
    }
}

//----------------------------------------------------------------------------
