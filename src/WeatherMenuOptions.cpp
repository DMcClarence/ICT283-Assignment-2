// WeatherMenuOptions.cpp
//
// Implementation of WeatherMenuOptions functions
//
// Version
// 01 01/05/2024 34085068
//      Started
// 02 15/05/2024 34085068
//      Encapsulate each Menu Into namespaces.
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "../includes/WeatherMenuOptions.h"
#include "../includes/WeatherRecUtilities.h"
#include "../includes/StatsCalcs.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::fixed;
using std::showpoint;
using std::setprecision;
using std::ofstream;

//----------------------------------------------------------------------------
// Global variables/defines

enum months {Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12};

//----------------------------------------------------------------------------
// Implementation Helper Function Prototypes

    // Functions Prototyped here are only used as Helpers for Implementation.
    // Not Designed for client use, hence why they're not prototyped in the interface.

    // Dedicated to Printing Mean and Standard Deviation of Wind Speed to the Screen
void PrintWindMeanStdDevToScreen(WeatherLogType &weatherLog, int month, int year);

    // Dedicated to Printing Mean and Standard Deviation of Temperature to the Screen
void PrintTempMeanStdDevToScreen(WeatherLogType &weatherLog, int month, int year);

    // Dedicated to Printing Total Solar Radiation to the Screen
void PrintSolarRadToScreen(WeatherLogType &weatherLog, int month, int year);

    // Dedicated to Printing Mean and Standard Deviation of float data members to a File
void PrintMeanStdDevToFile(WeatherLogType &weatherLog, float WeatherRecType::*p_Member, int month, int year, ofstream& output);

    // Dedicated to Printing Total Solar Radiation to a File
    // Designed to be last on each line of a CSV file (no comma printed)
void PrintSolarRadToFile(WeatherLogType &weatherLog, int month, int year, ofstream& output);

//----------------------------------------------------------------------------
// Function implementations

void WeatherMenuStrategy::WindSpeedStrategy::Execute(WeatherLogType &weatherLog)
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
void WeatherMenuStrategy::TemperatureStrategy::Execute(WeatherLogType &weatherLog)
{
    int year;

    cout << "Enter a Year: " << endl;
    cin >> year;
    cin.clear();

    cout << endl;
    cout << year << endl;
    for(int month = Jan; month <= Dec; month++)
    {
        PrintTempMeanStdDevToScreen(weatherLog, month, year);
    }
    cout << endl;
}

//----------------------------------------------------------------------------
void WeatherMenuStrategy::SolarRadiationStrategy::Execute(WeatherLogType &weatherLog)
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
void WeatherMenuStrategy::PrintToFileStrategy::Execute(WeatherLogType &weatherLog)
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
void PrintTempMeanStdDevToScreen(WeatherLogType &weatherLog, int month, int year)
{
    Vector<float> data;
    ExtractValuesFromWeatherLog(weatherLog, month, year, &WeatherRecType::m_t, data);

    cout << MonthToString(month) << ": ";
    if(data.GetSize() == 0)
    {
        cout << "No Data" << endl;
    }
    else
    {
        float avgTemp = CalcMeanOfVectorf(data);
        float tempStdDev = CalcStdDevOfVectorf(data);
        cout << fixed << showpoint << setprecision(2);
        cout << "average: " << avgTemp << " degrees C, stdev: " << tempStdDev << endl;
    }
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
