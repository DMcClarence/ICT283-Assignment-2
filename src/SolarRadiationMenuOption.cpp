// SolarRadiationMenuOption.cpp
//
// Implementation of SolarRadiationMenuOption Class
// Derived from WeatherMenuStrategy Abstract Class
//
// Version
// 01 17/04/2024 34085068
//      Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "../includes/SolarRadiationMenuOption.h"
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

    // Dedicated to Printing Total Solar Radiation to the Screen
void PrintSolarRadToScreen(WeatherLogType &weatherLog, int month, int year);

//----------------------------------------------------------------------------
// Function implementations

SolarRadiationMenuOption::SolarRadiationMenuOption()
{
}

//----------------------------------------------------------------------------
void SolarRadiationMenuOption::Execute(WeatherLogType &weatherLog)
{
    std::string yearStr;
    int year;

    std::cout << "Enter a Year: " << std::endl;
    std::cin >> yearStr;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    try
    {
        year = stoi(yearStr);
    }
    catch(...)
    {
        std::cout << std::endl;
        std::cout << "Invalid Year" << std::endl;
        std::cout << std::endl;
        return;
    }

    std::cout << std::endl;
    std::cout << year << std::endl;
    for(int month = Jan; month <= Dec; month++)
    {
        PrintSolarRadToScreen(weatherLog, month, year);
    }
    std::cout << std::endl;
}

//----------------------------------------------------------------------------
void PrintSolarRadToScreen(WeatherLogType &weatherLog, int month, int year)
{
    Vector<float> data;
    ExtractValuesFromWeatherLog(weatherLog, month, year, &WeatherRecType::m_sr, data);

    std::cout << MonthToString(month) << ": ";
    if(data.GetSize() == 0)
    {
        std::cout << "No Data" << std::endl;
    }
    else
    {
        float totalSR = StatsCalcs::CalcSumOfVectorf(data);
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << totalSR<< " kWh/m^2" << std::endl;
    }
}

//----------------------------------------------------------------------------
