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
#include <iomanip>
#include <fstream>

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
void PrintMeanStdDevToFile(WeatherLogType &weatherLog, float WeatherRecType::*p_Member, int month, int year, std::ofstream& output);

    // Dedicated to Printing Total Solar Radiation to a File
    // Designed to be last on each line of a CSV file (no comma printed)
void PrintSolarRadToFile(WeatherLogType &weatherLog, int month, int year, std::ofstream& output);

//----------------------------------------------------------------------------
// Function implementations

void WeatherMenuStrategy::WindSpeedStrategy::Execute(WeatherLogType &weatherLog)
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
void WeatherMenuStrategy::TemperatureStrategy::Execute(WeatherLogType &weatherLog)
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
void WeatherMenuStrategy::SolarRadiationStrategy::Execute(WeatherLogType &weatherLog)
{
    int year;

    std::cout << "Enter a Year: " << std::endl;
    std::cin >> year;
    std::cin.clear();

    std::cout << std::endl;
    std::cout << year << std::endl;
    for(int month = Jan; month <= Dec; month++)
    {
        PrintSolarRadToScreen(weatherLog, month, year);
    }
    std::cout << std::endl;
}

//----------------------------------------------------------------------------
void WeatherMenuStrategy::PrintToFileStrategy::Execute(WeatherLogType &weatherLog)
{
    std::ofstream output("WindSolarTemp.csv");
    int year;

    std::cout << "Enter a Year: " << std::endl;
    std::cin >> year;
    std::cin.clear();

    output << year << std::endl;
    for(int month = Jan; month <= Dec; month++)
    {
        output << MonthToString(month) << ",";
        PrintMeanStdDevToFile(weatherLog, &WeatherRecType::m_s, month, year, output);
        PrintMeanStdDevToFile(weatherLog, &WeatherRecType::m_t, month, year, output);
        PrintSolarRadToFile(weatherLog, month, year, output);
        output << std::endl;
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
        std::cout << "No Data" << std::endl;
    }
    else
    {
        float avgWindSpeed = StatsCalcs::CalcMeanOfVectorf(data);
        float windSpeedStdDev = StatsCalcs::CalcStdDevOfVectorf(data);
        std::cout << std::endl;
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "Average speed: " << avgWindSpeed << " km/h" << std::endl;
        std::cout << "Sample stdev: " << windSpeedStdDev << std::endl;
    }
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
        float avgTemp = StatsCalcs::CalcMeanOfVectorf(data);
        float tempStdDev = StatsCalcs::CalcStdDevOfVectorf(data);
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "average: " << avgTemp << " degrees C, stdev: " << tempStdDev << std::endl;
    }
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
void PrintMeanStdDevToFile(WeatherLogType &weatherLog, float WeatherRecType::*p_Member, int month, int year, std::ofstream& output)
{
    Vector<float> data;
    ExtractValuesFromWeatherLog(weatherLog, month, year, p_Member, data);

    if(data.GetSize() == 0)
    {
        output << " ,";
    }
    else
    {
        float avg = StatsCalcs::CalcMeanOfVectorf(data);
        float stdDev = StatsCalcs::CalcStdDevOfVectorf(data);
        output << std::fixed << std::showpoint << std::setprecision(2);
        output << avg << "(" << stdDev << "),";
    }
}

//----------------------------------------------------------------------------
void PrintSolarRadToFile(WeatherLogType &weatherLog, int month, int year, std::ofstream& output)
{
    Vector<float> data;
    ExtractValuesFromWeatherLog(weatherLog, month, year, &WeatherRecType::m_sr, data);

    if(data.GetSize() == 0)
    {
        output << " ";
    }
    else
    {
        float totalRad = StatsCalcs::CalcSumOfVectorf(data);
        output << std::fixed << std::showpoint << std::setprecision(2);
        output << totalRad;
    }
}

//----------------------------------------------------------------------------
