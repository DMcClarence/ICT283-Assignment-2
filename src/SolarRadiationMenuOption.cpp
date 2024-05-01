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
#include <string>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::fixed;
using std::showpoint;
using std::setprecision;

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
    int year;

    cout << "Enter a Year: " << endl;
    cin >> year;
    cin.clear();

    cout << endl;
    cout << year << endl;
    for(int month = Jan; month <= Dec; month++)
    {
        PrintSolarRadToScreen(weatherLog, month, year);
    }
    cout << endl;
}

//----------------------------------------------------------------------------
void PrintSolarRadToScreen(WeatherLogType &weatherLog, int month, int year)
{
    Vector<float> data;
    ExtractValuesFromWeatherLog(weatherLog, month, year, &WeatherRecType::m_sr, data);

    cout << MonthToString(month) << ": ";
    if(data.GetSize() == 0)
    {
        cout << "No Data" << endl;
    }
    else
    {
        float totalSR = CalcSumOfVectorf(data);
        cout << fixed << showpoint << setprecision(2);
        cout << totalSR<< " kWh/m^2" << endl;
    }
}

//----------------------------------------------------------------------------
