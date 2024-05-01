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

#include <fstream>
#include <sstream>
#include <stdexcept>

using std::istream;
using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::stoi;
using std::stof;
using std::istringstream;
using std::invalid_argument;
using std::cerr;

//----------------------------------------------------------------------------
// Global variables/defines

    // A Struct for the details of a Column
typedef struct
{
    int colNum;
    string colName;
}colOfInterest;

    // The Number of Columns in a Data File
const int numColsInFile = 18;

    // Number of Columns being Searched for
const int numWeatherRecCols = 4;

    // Name of Columns being Searched for
const string WeatherRecColNames[numWeatherRecCols] = {"WAST", "S", "T", "SR"};

enum WeatherRecCols{WAST, S, T, SR};

//----------------------------------------------------------------------------
// Implementation Helper Function Prototypes

    // Functions Prototyped here are only used as Helpers for Implementation.
    // Not Designed for client use, hence why they're not prototyped in the interface.

    // Stores the Names of the Columns being Searched for
void InitColsOfInterest(istream &input, colOfInterest *weatherRecCols);

    // Finds the Location of Each Column being Searched for
void FindWeatherRecCols(istringstream &line, colOfInterest *weatherRecCols);

    // Reads a Date Object from a Column Stream
void ReadDateFromCol(istringstream &col, WeatherRecType &temp);

    // Reads a Time Object from a Column Stream
void ReadTimeFromCol(istringstream &col, WeatherRecType &temp);

    // Reads a Column into a WeatherRecType Object
void ReadColIntoWeatherRec(string col, int colNum, const colOfInterest *weatherRecCols, WeatherRecType &weatherRec);

    // Convert String to a Float
bool CheckStringToFloatConversion(float &value, const string &strValue);

//----------------------------------------------------------------------------
// Function implementations

istream& operator>>(istream& input, Date& d)
{
    string day;
    string month;
    string year;
    int date;

    getline(input, day, '/');
    date = stoi(day);
    d.SetDay(date);

    getline(input, month, '/');
    date = stoi(month);
    d.SetMonth(date);

    getline(input, year);
    date = stoi(year);
    d.SetYear(date);

    return input;
}

//----------------------------------------------------------------------------
istream& operator>>(istream& input, Time& t)
{
    string hours;
    string minutes;
    int time;

    getline(input, hours, ':');
    time = stoi(hours);
    t.SetHours(time);

    getline(input, minutes);
    time = stoi(minutes);
    t.SetMinutes(time);

    return input;
}

//----------------------------------------------------------------------------
istream& operator>>(istream& input, WeatherLogType& data)
{
    colOfInterest weatherRecCols[numWeatherRecCols];
    WeatherRecType tempWeatherRec;
    string line;

    InitColsOfInterest(input, weatherRecCols);

    while(input.eof() == 0)
    {
        int col = 0;

        getline(input, line);
        if(line.empty())
        {
            break;
        }
        istringstream colStream(line);

        while(col < numColsInFile)
        {
            string column;
            getline(colStream, column, ',');
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
bool GetDataFileNameFromSrcFile(string &dataFileName)
{
    ifstream dataSource("data/data_source.txt");
    if(dataSource.rdstate() != 0)
    {
        cout << "Failed To Read File" << endl;
        return false;
    }
    getline(dataSource, dataFileName);
    dataSource.close();

    return true;
}

//----------------------------------------------------------------------------
bool ReadWeatherDataFromFile(const string &filename, WeatherLogType &weatherLog)
{
    ifstream dataFile("data/" + filename);
    if(dataFile.rdstate() != 0)
    {
        cout << "Failed To Read File" << endl;
        return false;
    }
    dataFile >> weatherLog;
    dataFile.close();

    return true;
}

//----------------------------------------------------------------------------
void InitColsOfInterest(istream &input, colOfInterest *weatherRecCols)
{
    string line;

    getline(input, line);
    istringstream headersStream(line);
    FindWeatherRecCols(headersStream, weatherRecCols);
}

//----------------------------------------------------------------------------
void FindWeatherRecCols(istringstream &line, colOfInterest *weatherRecCols)
{
    int i = 0;
    string col;

        // Populate struct with Column Names
    for(int j = WAST; j <= SR; j++)
    {
        weatherRecCols[j].colName = WeatherRecColNames[j];
    }

        // Find the column number for each column
    while(getline(line, col, ','))
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
void ReadDateFromCol(istringstream &col, WeatherRecType &temp)
{
    string date;

    getline(col, date, ' ');
    istringstream dateStream(date);
    dateStream >> temp.m_date;
}

//----------------------------------------------------------------------------
void ReadTimeFromCol(istringstream &col, WeatherRecType &temp)
{
    string time;

    getline(col, time);
    istringstream timeStream(time);
    timeStream >> temp.m_time;
}

//----------------------------------------------------------------------------
void ReadColIntoWeatherRec(string col, int colNum, const colOfInterest *weatherRecCols, WeatherRecType &weatherRec)
{
    if(colNum == weatherRecCols[WAST].colNum)
    {
        istringstream dateTime(col);
        ReadDateFromCol(dateTime, weatherRec);
        ReadTimeFromCol(dateTime, weatherRec);
        return;
    }

    float value;
    CheckStringToFloatConversion(value, col);

        // Even if Value is 0, still stores value.
        // If stof check fails, probably because of a string to indicate
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
bool CheckStringToFloatConversion(float &value, const string &strValue)
{
    try
    {
        value = stof(strValue);
        return true;
    }
    catch(const invalid_argument& argument)
    {
        cerr << "Invalid Argument to std::stof: " << argument.what() << endl;
        value = 0;
    }

    return false;
}

//----------------------------------------------------------------------------
