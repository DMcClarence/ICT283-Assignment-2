// PrintToFileMenuOption.cpp
//
// Implementation of PrintToFileMenuOption Class
// Derived from WeatherMenuStrategy Abstract Class
//
// Version
// 01 17/04/2024 34085068
//      Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "../includes/PrintToFileMenuOption.h"
#include "../includes/weatherRecUtilities.h"
#include "../includes/StatsCalcs.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ofstream;
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

    // Dedicated to Printing Mean and Standard Deviation of float data members to a File
void PrintMeanStdDevToFile(WeatherLogType &weatherLog, float WeatherRecType::*p_Member, int month, int year, ofstream& output);

    // Dedicated to Printing Total Solar Radiation to a File
    // Designed to be last on each line of a CSV file (no comma printed)
void PrintSolarRadToFile(WeatherLogType &weatherLog, int month, int year, ofstream& output);

//----------------------------------------------------------------------------
// Function implementations

PrintToFileMenuOption::PrintToFileMenuOption()
{
}

//----------------------------------------------------------------------------
void PrintToFileMenuOption::Execute(WeatherLogType &weatherLog)
{
    ofstream output("WindSolarTemp.csv");
    int year;

    cout << "Enter a Year: " << endl;
    cin >> year;
    cin.clear();

    output << year << endl;
    for(int month = Jan; month <= Dec; month++)
    {
        output << MonthToString(month) << ",";
        PrintMeanStdDevToFile(weatherLog, &WeatherRecType::m_s, month, year, output);
        PrintMeanStdDevToFile(weatherLog, &WeatherRecType::m_t, month, year, output);
        PrintSolarRadToFile(weatherLog, month, year, output);
        output << endl;
    }

    output.close();
}

//----------------------------------------------------------------------------
void PrintMeanStdDevToFile(WeatherLogType &weatherLog, float WeatherRecType::*p_Member, int month, int year, ofstream& output)
{
    Vector<float> data;
    ExtractValuesFromWeatherLog(weatherLog, month, year, p_Member, data);

    if(data.GetSize() == 0)
    {
        output << " ,";
    }
    else
    {
        float avg = CalcMeanOfVectorf(data);
        float stdDev = CalcStdDevOfVectorf(data);
        output << fixed << showpoint << setprecision(2);
        output << avg << "(" << stdDev << "),";
    }
}

//----------------------------------------------------------------------------
void PrintSolarRadToFile(WeatherLogType &weatherLog, int month, int year, ofstream& output)
{
    Vector<float> data;
    ExtractValuesFromWeatherLog(weatherLog, month, year, &WeatherRecType::m_sr, data);

    if(data.GetSize() == 0)
    {
        output << " ";
    }
    else
    {
        float totalRad = CalcSumOfVectorf(data);
        output << fixed << showpoint << setprecision(2);
        output << totalRad;
    }
}

//----------------------------------------------------------------------------
