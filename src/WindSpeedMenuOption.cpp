// WindSpeedMenuOption.cpp
//
// Implementation of WindSpeedMenuOption Class
// Derived from WeatherMenuStrategy Abstract Class
//
// Version
// 01 17/04/2024 34085068
//      Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "../includes/WindSpeedMenuOption.h"
#include "../includes/WeatherRecUtilities.h"
#include "../includes/StatsCalcs.h"

#include <iostream>
#include <iomanip>

//----------------------------------------------------------------------------
// Global variables/defines

//----------------------------------------------------------------------------
// Implementation Helper Function Prototypes

    // Functions Prototyped here are only used as Helpers for Implementation.
    // Not Designed for client use, hence why they're not prototyped in the interface.

    // Dedicated to Printing Mean and Standard Deviation of Wind Speed to the Screen
void PrintWindMeanStdDevToScreen(WeatherLogType &weatherLog, int month, int year);

//----------------------------------------------------------------------------
// Function implementations

WindSpeedMenuOption::WindSpeedMenuOption()
{
}

//----------------------------------------------------------------------------
void WindSpeedMenuOption::Execute(WeatherLogType &weatherLog)
{
    int year;
    int month;

    std::cout << "Enter a Year: ";
    std::cin >> year;
    std::cin.clear();
    std::cout << "Enter a numerical Month: ";
    std::cin >> month;
    std::cin.clear();
    std::cout << std::endl;

    std::cout << MonthToString(month) << " " << year << ": ";
    PrintWindMeanStdDevToScreen(weatherLog, month, year);
    std::cout << std::endl;
}

//----------------------------------------------------------------------------
void PrintWindMeanStdDevToScreen(WeatherLogType &weatherLog, int month, int year)
{
    Vector<float> data;
    ExtractValuesFromWeatherLog(weatherLog, month, year, &WeatherRecType::m_s, data);

    if(data.GetSize() == 0)
    {
        std::cout << "No Data" << std::endl;
    }
    else
    {
        float avgWindSpeed = CalcMeanOfVectorf(data);
        float windSpeedStdDev = CalcStdDevOfVectorf(data);
        std::cout << std::endl;
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "Average speed: " << avgWindSpeed << " km/h" << std::endl;
        std::cout << "Sample stdev: " << windSpeedStdDev << std::endl;
    }
}

//----------------------------------------------------------------------------
