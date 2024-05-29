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

#include "../includes/WeatherRecIO.h"

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
void PrintWindMeanStdDevToScreen(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst, int month, int year);

    // Dedicated to Printing Mean and Standard Deviation of Temperature to the Screen
void PrintTempMeanStdDevToScreen(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst, int month, int year);

    // Dedicated to Printing Total Solar Radiation to the Screen
void PrintSolarRadToScreen(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst, int month, int year);

    // Dedicated to Printing the sPCC of Wind Speed and Temperature to the Screen
void PrintStToScreen(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst, int month);

    // Dedicated to Printing the sPCC of Wind Speed and Solar Radiation to the Screen
void PrintSrToScreen(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst, int month);

    // Dedicated to Printing the sPCC of Temperature and Solar Radiation to the Screen
void PrintTrToScreen(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst, int month);

    // Dedicated to Printing Mean and Standard Deviation of float data members to a File
void PrintMeanStdDevMadToFile(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst, float WeatherRecType::*p_Member, int month, int year, std::ofstream& output);

    // Dedicated to Printing Total Solar Radiation to a File
    // Designed to be last on each line of a CSV file (no comma printed)
void PrintSolarRadToFile(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst, int month, int year, std::ofstream& output);

//----------------------------------------------------------------------------
// Function implementations

void WeatherMenuStrategy::WindSpeedStrategy::Execute(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst)
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
    PrintWindMeanStdDevToScreen(weatherLog, myMap, myBst, month, year);
    std::cout << std::endl;
}

//----------------------------------------------------------------------------
void WeatherMenuStrategy::TemperatureStrategy::Execute(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst)
{
    int year;

    std::cout << "Enter a Year: " << std::endl;
    std::cin >> year;
    std::cin.clear();

    std::cout << std::endl;
    std::cout << year << std::endl;
    for(int month = Jan; month <= Dec; month++)
    {
        PrintTempMeanStdDevToScreen(weatherLog, myMap, myBst, month, year);
    }
    std::cout << std::endl;
}

//----------------------------------------------------------------------------
void WeatherMenuStrategy::SolarRadiationStrategy::Execute(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst)
{
    int year;

    std::cout << "Enter a Year: " << std::endl;
    std::cin >> year;
    std::cin.clear();

    std::cout << std::endl;
    std::cout << year << std::endl;
    for(int month = Jan; month <= Dec; month++)
    {
        PrintSolarRadToScreen(weatherLog, myMap, myBst, month, year);
    }
    std::cout << std::endl;
}

//----------------------------------------------------------------------------
void WeatherMenuStrategy::SPCCStrategy::Execute(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst)
{
    int month;

    std::cout << "Enter a Numerical Month: " << std::endl;
    std::cin >> month;
    std::cin.clear();

    std::cout << std::endl;
    std::cout << "Sample Pearson Correlation Coefficinet for " << MonthToString(month) << std::endl;
    std::cout << std::endl;
    PrintStToScreen(weatherLog, myMap, myBst, month);
    PrintSrToScreen(weatherLog, myMap, myBst, month);
    PrintTrToScreen(weatherLog, myMap, myBst, month);
    std::cout << std::endl;
}

//----------------------------------------------------------------------------
void WeatherMenuStrategy::PrintToFileStrategy::Execute(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst)
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
        PrintMeanStdDevMadToFile(weatherLog, myMap, myBst, &WeatherRecType::m_s, month, year, output);
        PrintMeanStdDevMadToFile(weatherLog, myMap, myBst, &WeatherRecType::m_t, month, year, output);
        PrintSolarRadToFile(weatherLog, myMap, myBst, month, year, output);
        output << std::endl;
    }

    output.close();
}

//----------------------------------------------------------------------------
void PrintWindMeanStdDevToScreen(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst, int month, int year)
{
    Vector<int> requestedRecs;
    try
    {
        requestedRecs = myMap.at(year).at(month);
    }
    catch(...)
    {
        std::cout << "No Data" << std::endl;
        return;
    }

    WeatherLogType log;
    for(int i = 0; i < requestedRecs.GetSize(); i++)
    {
        log.PushBack(weatherLog[requestedRecs[i]]);
    }

    Vector<float> data;
    ExtractValuesFromWeatherLog(log, month, year, &WeatherRecType::m_s, data);

    RemoveInvalidData(data);

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
void PrintStToScreen(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst, int month)
{
    Vector<Vector<int>> requestedRecs;
    try
    {
        for(std::map<int, std::map<int, Vector<int>>>::iterator itr = myMap.begin(); itr != myMap.end(); itr++)
        {
            std::map<int, Vector<int>>& innerMyMap = itr->second;
            if(innerMyMap.find(month) != innerMyMap.end())
            {
                requestedRecs.PushBack(innerMyMap.at(month));
            }
        }
    }
    catch(...)
    {
        std::cout << "No Data" << std::endl;
        return;
    }

    WeatherLogType log;
    for(int i = 0; i < requestedRecs.GetSize(); i++)
    {
        for(int j = 0; j < requestedRecs[i].GetSize(); j++)
        {
            log.PushBack(weatherLog[requestedRecs[i][j]]);
        }
    }
    Vector<float> tempData;
    Vector<float> windSpeedData;
    ExtractValuesFromWeatherLog(log, &WeatherRecType::m_s, windSpeedData);
    ExtractValuesFromWeatherLog(log, &WeatherRecType::m_t, tempData);

    RemoveInvalidDataFromDataPairs(tempData, windSpeedData);

    if(windSpeedData.GetSize() == 0 || tempData.GetSize() == 0)
    {
        std::cout << "No Data" << std::endl;
    }
    else
    {
        float s_t = StatsCalcs::CalcSPCCOfVectorf(windSpeedData, tempData);
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "S_T: " << s_t << std::endl;
    }
}

//----------------------------------------------------------------------------
void PrintSrToScreen(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst, int month)
{
    Vector<Vector<int>> requestedRecs;
    try
    {
        for(std::map<int, std::map<int, Vector<int>>>::iterator itr = myMap.begin(); itr != myMap.end(); itr++)
        {
            std::map<int, Vector<int>>& innerMyMap = itr->second;
            if(innerMyMap.find(month) != innerMyMap.end())
            {
                requestedRecs.PushBack(innerMyMap.at(month));
            }
        }
    }
    catch(...)
    {
        std::cout << "No Data" << std::endl;
        return;
    }

    WeatherLogType log;
    for(int i = 0; i < requestedRecs.GetSize(); i++)
    {
        for(int j = 0; j < requestedRecs[i].GetSize(); j++)
        {
            log.PushBack(weatherLog[requestedRecs[i][j]]);
        }
    }
    Vector<float> solarRadData;
    Vector<float> windSpeedData;

    ExtractValuesFromWeatherLog(log, &WeatherRecType::m_s, windSpeedData);
    ExtractValuesFromWeatherLog(log, &WeatherRecType::m_sr, solarRadData);

    RemoveInvalidDataFromDataPairs(solarRadData, windSpeedData);

    if(windSpeedData.GetSize() == 0 || solarRadData.GetSize() == 0)
    {
        std::cout << "No Data" << std::endl;
    }
    else
    {
        float s_r = StatsCalcs::CalcSPCCOfVectorf(solarRadData, windSpeedData);
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "S_R: " << s_r << std::endl;
    }
}

//----------------------------------------------------------------------------
void PrintTrToScreen(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst, int month)
{
    Vector<Vector<int>> requestedRecs;
    try
    {
        for(std::map<int, std::map<int, Vector<int>>>::iterator itr = myMap.begin(); itr != myMap.end(); itr++)
        {
            std::map<int, Vector<int>>& innerMyMap = itr->second;
            if(innerMyMap.find(month) != innerMyMap.end())
            {
                requestedRecs.PushBack(innerMyMap.at(month));
            }
        }
    }
    catch(...)
    {
        std::cout << "No Data" << std::endl;
        return;
    }

    WeatherLogType log;
    for(int i = 0; i < requestedRecs.GetSize(); i++)
    {
        for(int j = 0; j < requestedRecs[i].GetSize(); j++)
        {
            log.PushBack(weatherLog[requestedRecs[i][j]]);
        }
    }
    Vector<float> tempData;
    Vector<float> solarRadData;

    ExtractValuesFromWeatherLog(log, &WeatherRecType::m_sr, solarRadData);
    ExtractValuesFromWeatherLog(log, &WeatherRecType::m_t, tempData);

    RemoveInvalidDataFromDataPairs(tempData, solarRadData);

    if(solarRadData.GetSize() == 0 || tempData.GetSize() == 0)
    {
        std::cout << "No Data" << std::endl;
    }
    else
    {
        float t_r = StatsCalcs::CalcSPCCOfVectorf(solarRadData, tempData);
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "T_R: " << t_r << std::endl;
    }
}

//----------------------------------------------------------------------------
void PrintTempMeanStdDevToScreen(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst, int month, int year)
{
    Vector<float> data;
    ExtractValuesFromWeatherLog(weatherLog, month, year, &WeatherRecType::m_t, data);

    RemoveInvalidData(data);

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
void PrintSolarRadToScreen(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst, int month, int year)
{
    Vector<float> data;
    ExtractValuesFromWeatherLog(weatherLog, month, year, &WeatherRecType::m_sr, data);

    RemoveInvalidData(data);

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
void PrintMeanStdDevMadToFile(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst, float WeatherRecType::*p_Member, int month, int year, std::ofstream& output)
{
    Vector<float> data;
    ExtractValuesFromWeatherLog(weatherLog, month, year, p_Member, data);

    RemoveInvalidData(data);

    if(data.GetSize() == 0)
    {
        output << " ,";
    }
    else
    {
        float avg = StatsCalcs::CalcMeanOfVectorf(data);
        float stdDev = StatsCalcs::CalcStdDevOfVectorf(data);
        float mad = StatsCalcs::CalcMADOfVectorf(data);
        output << std::fixed << std::showpoint << std::setprecision(2);
        output << avg << "(" << stdDev << ", " << mad << "),";
    }
}

//----------------------------------------------------------------------------
void PrintSolarRadToFile(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<KeyValue<int, WeatherRecType>> &myBst, int month, int year, std::ofstream& output)
{
    Vector<float> data;
    ExtractValuesFromWeatherLog(weatherLog, month, year, &WeatherRecType::m_sr, data);

    RemoveInvalidData(data);

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
