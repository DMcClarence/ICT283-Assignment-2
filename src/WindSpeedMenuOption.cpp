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

    cout << "Enter a Year: ";
    cin >> year;
    cin.clear();
    cout << "Enter a numerical Month: ";
    cin >> month;
    cin.clear();
    cout << endl;

    cout << MonthToString(month) << " " << year << ": ";
    PrintWindMeanStdDevToScreen(weatherLog, month, year);
    cout << endl;
}

//----------------------------------------------------------------------------
void PrintWindMeanStdDevToScreen(WeatherLogType &weatherLog, int month, int year)
{
    Vector<float> data;
    ExtractValuesFromWeatherLog(weatherLog, month, year, &WeatherRecType::m_s, data);

    if(data.GetSize() == 0)
    {
        cout << "No Data" << endl;
    }
    else
    {
        float avgWindSpeed = CalcMeanOfVectorf(data);
        float windSpeedStdDev = CalcStdDevOfVectorf(data);
        cout << endl;
        cout << fixed << showpoint << setprecision(2);
        cout << "Average speed: " << avgWindSpeed << " km/h" << endl;
        cout << "Sample stdev: " << windSpeedStdDev << endl;
    }
}

//----------------------------------------------------------------------------
