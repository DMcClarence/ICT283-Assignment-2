// weatherRecIO.cpp
//
// Weather Record IO functions implementation
//
// Version
// 01 14/04/2024 34085068
//      Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "../includes/WeatherRecIO.h"
#include "../includes/WeatherRecUtilities.h"
#include "../includes/Stack.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>

//----------------------------------------------------------------------------
// Global variables/defines

    // A Struct for the details of a Column
typedef struct
{
    int colNum;
    std::string colName;
}colOfInterest;

    // The Number of Columns in a Data File
const int numColsInFile = 18;

    // Number of Columns being Searched for
const int numWeatherRecCols = 4;

    // Name of Columns being Searched for
const std::string WeatherRecColNames[numWeatherRecCols] = {"WAST", "S", "T", "SR"};

enum WeatherRecCols{WAST, S, T, SR};

std::string emptyLine = ",,,,,,,,,,,,,,,,,";

//----------------------------------------------------------------------------
// Implementation Helper Function Prototypes

    // Functions Prototyped here are only used as Helpers for Implementation.
    // Not Designed for client use, hence why they're not prototyped in the interface.

    // Stores the Names of the Columns being Searched for
void InitColsOfInterest(std::istream &input, colOfInterest *weatherRecCols);

    // Finds the Location of Each Column being Searched for
void FindWeatherRecCols(std::istringstream &line, colOfInterest *weatherRecCols);

    // Reads a Date Object from a Column Stream
void ReadDateFromCol(std::istringstream &col, WeatherRecType &temp);

    // Reads a Time Object from a Column Stream
void ReadTimeFromCol(std::istringstream &col, WeatherRecType &temp);

    // Reads a Column into a WeatherRecType Object
void ReadColIntoWeatherRec(std::string col, int colNum, const colOfInterest *weatherRecCols, WeatherRecType &weatherRec);

    // Convert std::string to a Float
bool CheckStringToFloatConversion(float &value, const std::string &strValue);

//----------------------------------------------------------------------------
// Function implementations

std::istream& operator>>(std::istream& input, Date& d)
{
    std::string day;
    std::string month;
    std::string year;
    int date;

    std::getline(input, day, '/');
    try
    {
        date = std::stoi(day);
    }
    catch(...)
    {
        throw;
    }
    d.SetDay(date);

    std::getline(input, month, '/');
    try
    {
        date = std::stoi(month);
    }
    catch(...)
    {
        throw;
    }
    d.SetMonth(date);

    std::getline(input, year);
    try
    {
        date = std::stoi(year);
    }
    catch(...)
    {
        throw;
    }

    d.SetYear(date);

    return input;
}

//----------------------------------------------------------------------------
std::istream& operator>>(std::istream& input, Time& t)
{
    std::string hours;
    std::string minutes;
    int time;

    std::getline(input, hours, ':');
    try
    {
        time = std::stoi(hours);
    }
    catch(...)
    {
        throw;
    }

    t.SetHours(time);

    std::getline(input, minutes);
    try
    {
       time = std::stoi(minutes);
    }
    catch(...)
    {
        throw;
    }
    t.SetMinutes(time);

    return input;
}

//----------------------------------------------------------------------------
std::istream& operator>>(std::istream& input, WeatherLogType& data)
{
    colOfInterest weatherRecCols[numWeatherRecCols];
    WeatherRecType tempWeatherRec;
    std::string line;

    InitColsOfInterest(input, weatherRecCols);

    while(input.eof() == 0)
    {
        int col = 0;

        std::getline(input, line);
        if(line == emptyLine || line.empty())
        {
            continue;
        }
        std::istringstream colStream(line);

        while(col < numColsInFile)
        {
            std::string column;
            std::getline(colStream, column, ',');
            ReadColIntoWeatherRec(column, col, weatherRecCols, tempWeatherRec);
            column.clear();
            col++;
        }
        line.clear();
        data.PushBack(tempWeatherRec);
    }

    return input;
}

//----------------------------------------------------------------------------
bool GetDataFileNameFromSrcFile(Stack<std::string> &fileNameStack)
{
    std::ifstream dataSource("data/data_source.txt");
    std::string fileName;
    if(dataSource.rdstate() != 0)
    {
        std::cout << "Failed To Read File" << std::endl;
        return false;
    }

    while(dataSource.eof() == 0)
    {
        std::getline(dataSource, fileName);
        fileNameStack.Push(fileName);
    }
    dataSource.close();

    return true;
}

//----------------------------------------------------------------------------
bool ReadWeatherDataFromFile(std::string &filename, WeatherLogType &weatherLog)
{
    std::ifstream dataFile("data/" + filename);
    if(dataFile.rdstate() != 0)
    {
        std::cout << "Failed To Read File" << std::endl;
        return false;
    }
    dataFile >> weatherLog;
    dataFile.close();

    return true;
}

//----------------------------------------------------------------------------
void InitColsOfInterest(std::istream &input, colOfInterest *weatherRecCols)
{
    std::string line;

    std::getline(input, line);
    std::istringstream headersStream(line);
    FindWeatherRecCols(headersStream, weatherRecCols);
}

//----------------------------------------------------------------------------
void FindWeatherRecCols(std::istringstream &line, colOfInterest *weatherRecCols)
{
    int i = 0;
    std::string col;

        // Populate struct with Column Names
    for(int j = WAST; j <= SR; j++)
    {
        weatherRecCols[j].colName = WeatherRecColNames[j];
    }

        // Find the column number for each column
    while(std::getline(line, col, ','))
    {
        for(int j = WAST; j <= SR; j++)
        {
            if(col == weatherRecCols[j].colName)
            {
                weatherRecCols[j].colNum = i;
            }
        }
        i++;
    }
}

//----------------------------------------------------------------------------
void ReadDateFromCol(std::istringstream &col, WeatherRecType &temp)
{
    std::string date;

    std::getline(col, date, ' ');
    std::istringstream dateStream(date);
    try
    {
        dateStream >> temp.m_date;
    }
    catch(...)
    {
        throw;
    }

}

//----------------------------------------------------------------------------
void ReadTimeFromCol(std::istringstream &col, WeatherRecType &temp)
{
    std::string time;

    std::getline(col, time);
    std::istringstream timeStream(time);
    try
    {
        timeStream >> temp.m_time;
    }
    catch(...)
    {
        throw;
    }

}

//----------------------------------------------------------------------------
void ReadColIntoWeatherRec(std::string col, int colNum, const colOfInterest *weatherRecCols, WeatherRecType &weatherRec)
{
    if(colNum == weatherRecCols[WAST].colNum)
    {
        std::istringstream dateTime(col);
        try
        {
            ReadDateFromCol(dateTime, weatherRec);
            ReadTimeFromCol(dateTime, weatherRec);
        }
        catch(...)
        {
            std::cout << "Error Reading Date/Time" << std::endl;
            exit(-1);
        }

        return;
    }

    float value;
    CheckStringToFloatConversion(value, col);

        // Even if Value is 0, still stores value.
        // If std::stof check fails, probably because of a std::string to indicate
        // that the Sensor was offline.
    if(colNum == weatherRecCols[S].colNum)
    {
        ToKMperHr(value);
        weatherRec.m_s = value;
    }
    else if(colNum == weatherRecCols[T].colNum)
    {
        weatherRec.m_t = value;
    }
    else if(colNum == weatherRecCols[SR].colNum)
    {
        if(value >= 100)
        {
            TokWh(value);
            weatherRec.m_sr = value;
        }
        else
        {
            weatherRec.m_sr = 0;
        }
    }
}

//----------------------------------------------------------------------------
bool CheckStringToFloatConversion(float &value, const std::string &strValue)
{
    bool converted = true;

    try
    {
        value = std::stof(strValue);
    }
    catch(...)
    {
        converted = false;
        value = 0;
    }

    return converted;
}

//----------------------------------------------------------------------------
