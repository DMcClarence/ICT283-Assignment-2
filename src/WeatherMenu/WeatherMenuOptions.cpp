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

#include "../../includes/WeatherMenu/WeatherMenuOptions.h"
#include "../../includes/WeatherRec/WeatherRecUtilities.h"
#include "../../includes/StatsCalcs/StatsCalcs.h"

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
void PrintWindMeanStdDevToScreen(const Vector<float>& windSpeedData);

    // Dedicated to Printing Mean and Standard Deviation of Temperature to the Screen
void PrintTempMeanStdDevToScreen(const Vector<float>& tempData);

    // Dedicated to Printing Total Solar Radiation to the Screen
void PrintSolarRadToScreen(const Vector<float>& solarRadData);

    // Dedicated to Printing the sPCC of Wind Speed and Temperature to the Screen
void PrintStToScreen(const std::pair<Vector<float>, Vector<float>>& st);

    // Dedicated to Printing the sPCC of Wind Speed and Solar Radiation to the Screen
void PrintSrToScreen(const std::pair<Vector<float>, Vector<float>>& sr);

    // Dedicated to Printing the sPCC of Temperature and Solar Radiation to the Screen
void PrintTrToScreen(const std::pair<Vector<float>, Vector<float>>& tr);

    // Dedicated to Printing Mean and Standard Deviation of float data members to a File
std::ofstream& PrintMeanStdDevMadToFile(std::ofstream& output, const Vector<float>& data);

    // Dedicated to Printing Total Solar Radiation to a File
    // Designed to be last on each line of a CSV file (no comma printed)
std::ofstream& PrintSolarRadToFile(std::ofstream& output, const Vector<float>& data);

    // Returns a Vector<float> of the Record Data from a Specific Month and Year for a specific Data Members
Vector<float> GetRequestedData(WeatherDataStorage& weatherData, int month, int year, float WeatherRecType::*p_Member);

    // Retrieves the Record Data Pairs from a Specific Month of Every Stored Year
void GetRequestedDataPair(WeatherDataStorage& weatherData, int month, std::pair<Vector<float>, Vector<float>>& data, float WeatherRecType::*p1_Member, float WeatherRecType::*p2_Member);

//----------------------------------------------------------------------------
// Function implementations

void WeatherMenuStrategy::WindSpeedStrategy::Execute(WeatherDataStorage& weatherData)
{
    std::string enteredYear;
    std::string enteredMonth;
    std::string monthString;
    int year;
    int month;

    std::cout << "Enter a Year: ";
    std::cin >> enteredYear;
    std::cin.clear();
    try
    {
        year = std::stoi(enteredYear);
    }
    catch(...)
    {
        std::cout << std::endl;
        std::cout << "Invalid Year" << std::endl;
        std::cout << std::endl;
        return;
    }
    std::cout << "Enter a numerical Month: ";
    std::cin >> enteredMonth;
    std::cin.clear();
    try
    {
        month = std::stoi(enteredMonth);
        monthString = WeatherRecUtilities::MonthToString(month);
    }
    catch(...)
    {
        std::cout << std::endl;
        std::cout << "Invalid Month" << std::endl;
        std::cout << std::endl;
        return;
    }
    std::cout << std::endl;

    Vector<float> windSpeedData = GetRequestedData(weatherData, month, year, &WeatherRecType::m_s);
    WeatherRecUtilities::RemoveInvalidData(windSpeedData);

    std::cout << monthString << " " << year << ": ";
    if(windSpeedData.GetSize() == 0)
    {
        std::cout << "No Data" << std::endl;
    }
    else
    {
        PrintWindMeanStdDevToScreen(windSpeedData);
    }
    std::cout << std::endl;
}

//----------------------------------------------------------------------------
void WeatherMenuStrategy::TemperatureStrategy::Execute(WeatherDataStorage& weatherData)
{
    std::string enteredYear;
    int year;

    std::cout << "Enter a Year: " << std::endl;
    std::cin >> enteredYear;
    std::cin.clear();
    try
    {
        year = std::stoi(enteredYear);
    }
    catch(...)
    {
        std::cout << std::endl;
        std::cout << "Invalid Year" << std::endl;
        std::cout << std::endl;
        return;
    }
    Vector<float> tempData;

    std::cout << std::endl;
    std::cout << year << std::endl;
    for(int month = Jan; month <= Dec; month++)
    {
        tempData = GetRequestedData(weatherData, month, year, &WeatherRecType::m_t);
        WeatherRecUtilities::RemoveInvalidData(tempData);

        std::cout << WeatherRecUtilities::MonthToString(month) << ": ";
        if(tempData.GetSize() == 0)
        {
            std::cout << "No Data" << std::endl;
        }
        else
        {
            PrintTempMeanStdDevToScreen(tempData);
        }
    }
    std::cout << std::endl;
}

//----------------------------------------------------------------------------
void WeatherMenuStrategy::SolarRadiationStrategy::Execute(WeatherDataStorage& weatherData)
{
    std::string enteredYear;
    int year;

    std::cout << "Enter a Year: ";
    std::cin >> enteredYear;
    std::cin.clear();
    try
    {
        year = std::stoi(enteredYear);
    }
    catch(...)
    {
        std::cout << std::endl;
        std::cout << "Invalid Year" << std::endl;
        std::cout << std::endl;
        return;
    }
    Vector<float> solarRadData;

    std::cout << std::endl;
    std::cout << year << std::endl;
    for(int month = Jan; month <= Dec; month++)
    {
        solarRadData = GetRequestedData(weatherData, month, year, &WeatherRecType::m_t);
        WeatherRecUtilities::RemoveInvalidData(solarRadData);

        std::cout << WeatherRecUtilities::MonthToString(month) << ": ";
        if(solarRadData.GetSize() == 0)
        {
            std::cout << "No Data" << std::endl;
        }
        else
        {
            PrintSolarRadToScreen(solarRadData);
        }
    }
}

//----------------------------------------------------------------------------
void WeatherMenuStrategy::SPCCStrategy::Execute(WeatherDataStorage& weatherData)
{
    std::string enteredMonth;
    int month;
    std::string monthString;

    std::cout << "Enter a numerical Month: ";
    std::cin >> enteredMonth;
    std::cin.clear();
    try
    {
        month = std::stoi(enteredMonth);
        monthString = WeatherRecUtilities::MonthToString(month);
    }
    catch(...)
    {
        std::cout << std::endl;
        std::cout << "Invalid Month" << std::endl;
        std::cout << std::endl;
        return;
    }

    std::pair<Vector<float>, Vector<float>> st;
    std::pair<Vector<float>, Vector<float>> sr;
    std::pair<Vector<float>, Vector<float>> tr;

    std::cout << std::endl;
    std::cout << "Sample Pearson Correlation Coefficinet for " << monthString << std::endl;
    std::cout << std::endl;
    GetRequestedDataPair(weatherData, month, st, &WeatherRecType::m_s, &WeatherRecType::m_t);
    WeatherRecUtilities::RemoveInvalidDataFromDataPairs(st);
    PrintStToScreen(st);

    GetRequestedDataPair(weatherData, month, sr, &WeatherRecType::m_s, &WeatherRecType::m_sr);
    WeatherRecUtilities::RemoveInvalidDataFromDataPairs(sr);
    PrintSrToScreen(sr);

    GetRequestedDataPair(weatherData, month, tr, &WeatherRecType::m_t, &WeatherRecType::m_sr);
    WeatherRecUtilities::RemoveInvalidDataFromDataPairs(tr);
    PrintTrToScreen(tr);
    std::cout << std::endl;
}

//----------------------------------------------------------------------------
void WeatherMenuStrategy::PrintToFileStrategy::Execute(WeatherDataStorage& weatherData)
{
    std::ofstream output("WindSolarTemp.csv");
    std::string enteredYear;
    int year;

    std::cout << "Enter a Year: ";
    std::cin >> enteredYear;
    std::cin.clear();
    try
    {
        year = std::stoi(enteredYear);
    }
    catch(...)
    {
        std::cout << std::endl;
        std::cout << "Invalid Year" << std::endl;
        std::cout << std::endl;
        output.close();
        return;
    }

    bool isData = false;
    for(int month = Jan; month <= Dec; month++)
    {
        if(weatherData.m_yearMonthBST.Search(WeatherRecUtilities::CreateMonthYearKey(year, month)))
        {
            isData = true;
            break;
        }
    }

    output << year << std::endl;

    if(!isData)
    {
        output << "No Data" << std::endl;
        return;
    }

    for(int month = Jan; month <= Dec; month++)
    {
        std::tuple<Vector<float>, Vector<float>, Vector<float>> data;
        std::get<0>(data) = GetRequestedData(weatherData, month, year, &WeatherRecType::m_s);
        WeatherRecUtilities::RemoveInvalidData(std::get<0>(data));

        std::get<1>(data) = GetRequestedData(weatherData, month, year, &WeatherRecType::m_t);
        WeatherRecUtilities::RemoveInvalidData(std::get<1>(data));

        std::get<2>(data) = GetRequestedData(weatherData, month, year, &WeatherRecType::m_sr);
        WeatherRecUtilities::RemoveInvalidData(std::get<2>(data));

        if(std::get<0>(data).GetSize() != 0 || std::get<1>(data).GetSize() != 0 || std::get<2>(data).GetSize() != 0)
        {
            output << WeatherRecUtilities::MonthToString(month) << ",";
            PrintMeanStdDevMadToFile(output, std::get<0>(data));
            PrintMeanStdDevMadToFile(output, std::get<1>(data));
            PrintSolarRadToFile(output, std::get<2>(data));
            output << std::endl;
        }
    }

    output.close();
}

//----------------------------------------------------------------------------
void PrintWindMeanStdDevToScreen(const Vector<float>& windSpeedData)
{
    float avgWindSpeed = StatsCalcs::CalcMeanOfVectorf(windSpeedData);
    float windSpeedStdDev = StatsCalcs::CalcStdDevOfVectorf(windSpeedData);
    std::cout << std::endl;
    std::cout << std::fixed << std::showpoint << std::setprecision(1);
    std::cout << "Average speed: " << avgWindSpeed << " km/h" << std::endl;
    std::cout << "Sample stdev: " << windSpeedStdDev << std::endl;
}

//----------------------------------------------------------------------------
void PrintStToScreen(const std::pair<Vector<float>, Vector<float>>& st)
{
    if(st.first.GetSize() == 0 || st.second.GetSize() == 0)
    {
        std::cout << "No Data" << std::endl;
    }
    else
    {
        float s_t = StatsCalcs::CalcSPCCOfVectorf(st.first, st.second);
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "S_T: " << s_t << std::endl;
    }
}

//----------------------------------------------------------------------------
void PrintSrToScreen(const std::pair<Vector<float>, Vector<float>>& sr)
{
    if(sr.first.GetSize() == 0 || sr.second.GetSize() == 0)
    {
        std::cout << "No Data" << std::endl;
    }
    else
    {
        float s_r = StatsCalcs::CalcSPCCOfVectorf(sr.first, sr.second);
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "S_R: " << s_r << std::endl;
    }
}

//----------------------------------------------------------------------------
void PrintTrToScreen(const std::pair<Vector<float>, Vector<float>>& tr)
{
    if(tr.first.GetSize() == 0 || tr.second.GetSize() == 0)
    {
        std::cout << "No Data" << std::endl;
    }
    else
    {
        float t_r = StatsCalcs::CalcSPCCOfVectorf(tr.first, tr.second);
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << "T_R: " << t_r << std::endl;
    }
}

//----------------------------------------------------------------------------
void PrintTempMeanStdDevToScreen(const Vector<float>& tempData)
{
    float avgTemp = StatsCalcs::CalcMeanOfVectorf(tempData);
    float tempStdDev = StatsCalcs::CalcStdDevOfVectorf(tempData);
    std::cout << std::fixed << std::showpoint << std::setprecision(1);
    std::cout << "average: " << avgTemp << " degrees C, stdev: " << tempStdDev << std::endl;
}

//----------------------------------------------------------------------------
void PrintSolarRadToScreen(const Vector<float>& solarRadData)
{
    float totalSR = StatsCalcs::CalcSumOfVectorf(solarRadData);
    std::cout << std::fixed << std::showpoint << std::setprecision(1);
    std::cout << totalSR<< " kWh/m^2" << std::endl;
}

//----------------------------------------------------------------------------
std::ofstream& PrintMeanStdDevMadToFile(std::ofstream& output, const Vector<float>& data)
{
    if(data.GetSize() == 0)
    {
        output << " ,";
    }
    else
    {
        float avg = StatsCalcs::CalcMeanOfVectorf(data);
        float stdDev = StatsCalcs::CalcStdDevOfVectorf(data);
        float mad = StatsCalcs::CalcMADOfVectorf(data);
        output << std::fixed << std::showpoint << std::setprecision(1);
        output << avg << "(" << stdDev << ", " << mad << "),";
    }

    return output;
}

//----------------------------------------------------------------------------
std::ofstream& PrintSolarRadToFile(std::ofstream& output, const Vector<float>& data)
{
    if(data.GetSize() == 0)
    {
        output << " ";
    }
    else
    {
        float totalRad = StatsCalcs::CalcSumOfVectorf(data);
        output << std::fixed << std::showpoint << std::setprecision(1);
        output << totalRad;
    }

    return output;
}

//----------------------------------------------------------------------------
Vector<float> GetRequestedData(WeatherDataStorage& weatherData, int month, int year, float WeatherRecType::*p_Member)
{
    Vector<float> data;

    if(weatherData.m_yearMonthBST.Search(WeatherRecUtilities::CreateMonthYearKey(year, month)))
    {
        Vector<int> recordIndexes = weatherData.m_weatherLogMap[year][month];

        WeatherLogType log;
        for(int i = 0; i < recordIndexes.GetSize(); i++)
        {
            log.PushBack(weatherData.m_weatherLog[recordIndexes[i]]);
        }

        data = WeatherRecUtilities::ExtractValuesFromWeatherLog(log, month, year, p_Member);
    }

    return data;
}

//----------------------------------------------------------------------------
void GetRequestedDataPair(WeatherDataStorage& weatherData, int month, std::pair<Vector<float>, Vector<float>>& data, float WeatherRecType::*p1_Member, float WeatherRecType::*p2_Member)
{
    Vector<Vector<int>> recordIndexes;

    for(Map<int, Map<int, Vector<int>>>::iterator itr = weatherData.m_weatherLogMap.Begin(); itr != weatherData.m_weatherLogMap.End(); ++itr)
    {
        if(weatherData.m_yearMonthBST.Search(WeatherRecUtilities::CreateMonthYearKey(itr->first, month)))
        {
            recordIndexes.PushBack(weatherData.m_weatherLogMap[itr->first][month]);
        }
    }

    WeatherLogType log;
    for(int i = 0; i < recordIndexes.GetSize(); i++)
    {
        for(int j = 0; j < recordIndexes[i].GetSize(); j++)
        {
            log.PushBack(weatherData.m_weatherLog[recordIndexes[i][j]]);
        }
    }

    data.first = WeatherRecUtilities::ExtractValuesFromWeatherLog(log, p1_Member);
    data.second = WeatherRecUtilities::ExtractValuesFromWeatherLog(log, p2_Member);
}

//----------------------------------------------------------------------------
Vector<void (*)(WeatherDataStorage&)>& WeatherMenuStrategy::WeatherMenuContext::InitWeatherMenuContext(Vector<void (*)(WeatherDataStorage&)>& menuOptions)
{
    menuOptions.PushBack(WeatherMenuStrategy::WindSpeedStrategy::Execute);
    menuOptions.PushBack(WeatherMenuStrategy::TemperatureStrategy::Execute);
    menuOptions.PushBack(WeatherMenuStrategy::SPCCStrategy::Execute);
    menuOptions.PushBack(WeatherMenuStrategy::PrintToFileStrategy::Execute);

    return menuOptions;
}
