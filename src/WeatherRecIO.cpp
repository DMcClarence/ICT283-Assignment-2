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
#include "../includes/VectorUtilities.h"
#include "../includes/BSTUtilities.h"

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

    // Line with no Data in any Column
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

    // Returns a Vector with Count for Each File Set to 0
Vector<int> InitFileLineCountVec(int numOfLogs);

    // Indexes a Record by Year and Month
void indexRecordInMap(int index, WeatherRecType& rec, Map<int, Map<int, Vector<int>>> &indexedMap);

    // Finds the Earliest Dated/Timed Record between Logs
int findEarliestRecordBetweenFiles(Vector<WeatherLogType>& log, Vector<int>& lineCount);

    // Assigns a Key value to a Record
KeyValue<int, WeatherRecType> assignRecKey(int key, WeatherRecType& rec);

    // Removes logs for Completed Files
void RemoveCompletedFiles(Vector<WeatherLogType> &logs, Vector<int> &lineCount);

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
bool ReadWeatherDataFromFiles(Stack<std::string> &fileStack, WeatherLogType &weatherLog, Map<int, Map<int, Vector<int>>> &weatherRecMap, BST<int> &myBst)
{
    Vector<WeatherLogType> logs;

    while(!fileStack.IsEmpty())
    {
        std::string filename;
        fileStack.Pop(filename);
        std::ifstream dataFile("data/" + filename);
        if(dataFile.rdstate() != 0)
        {
            std::cout << "Failed To Read File: " << filename << std::endl;
            return false;
        }
        WeatherLogType fileData;
        dataFile >> fileData;
        logs.PushBack(fileData);
        dataFile.close();
    }

    Vector<KeyValue<int, WeatherRecType>> index;
    KeyValue<int, WeatherRecType> keyVal;
    Vector<int> yearMonths;
    int temp;
    int currentIndex = 0;
    if(logs.GetSize() > 0)
    {
        Vector<int> lineCount = InitFileLineCountVec(logs.GetSize());

        WeatherRecType earliestRec;
        int earliestIndex;

            // Add Values in Order
        while(logs.GetSize() > 1)
        {
            earliestIndex = findEarliestRecordBetweenFiles(logs, lineCount);
            earliestRec = logs[earliestIndex][lineCount[earliestIndex]];

            if(weatherLog.GetSize() == 0 ||
                (earliestRec.m_date != weatherLog[weatherLog.GetSize() - 1].m_date) ||
               (earliestRec.m_date == weatherLog[weatherLog.GetSize() - 1].m_date && earliestRec.m_time != weatherLog[weatherLog.GetSize() - 1].m_time))
            {
                weatherLog.PushBack(earliestRec);
                keyVal = assignRecKey((weatherLog.GetSize() - 1), earliestRec);
                index.PushBack(keyVal);
                indexRecordInMap((weatherLog.GetSize() - 1), earliestRec, weatherRecMap);
                temp = (earliestRec.m_date.GetYear() * 100) + earliestRec.m_date.GetMonth();
                yearMonths.PushBack(temp);
            }
            lineCount[earliestIndex]++;

            RemoveCompletedFiles(logs, lineCount);

        }

            // Add Remaining Values
        while(lineCount[0] < logs[0].GetSize())
        {
            if(weatherLog.GetSize() == 0 ||
                (logs[0][lineCount[0]].m_date != weatherLog[weatherLog.GetSize() - 1].m_date) ||
               (logs[0][lineCount[0]].m_date == weatherLog[weatherLog.GetSize() - 1].m_date && logs[0][lineCount[0]].m_time != weatherLog[weatherLog.GetSize() - 1].m_time))
            {
                weatherLog.PushBack(logs[0][lineCount[0]]);
                keyVal = assignRecKey(weatherLog.GetSize() - 1, logs[0][lineCount[0]]);
                index.PushBack(keyVal);
                indexRecordInMap((weatherLog.GetSize() - 1), logs[0][lineCount[0]], weatherRecMap);
                temp = (logs[0][lineCount[0]].m_date.GetYear() * 100) + logs[0][lineCount[0]].m_date.GetMonth();
                yearMonths.PushBack(temp);
            }
            lineCount[0]++;
        }
    }

    MergeSortVector(yearMonths);
    InsertSortedVectorToBST(0, (yearMonths.GetSize() - 1), myBst, yearMonths);

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
            weatherRec.m_sr = NAN;
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
        value = NAN;
    }

    return converted;
}

//----------------------------------------------------------------------------
Vector<int> InitFileLineCountVec(int numOfLogs)
{
    Vector<int> count;
    for(int i = 0; i < numOfLogs; i++)
    {
        count.PushBack(0);
    }

    return count;
}

//----------------------------------------------------------------------------
void indexRecordInMap(int index, WeatherRecType &rec, Map<int, Map<int, Vector<int>>> &indexedMap)
{
    indexedMap[rec.m_date.GetYear()][rec.m_date.GetMonth()].PushBack(index);
}

//----------------------------------------------------------------------------
int findEarliestRecordBetweenFiles(Vector<WeatherLogType>& logs, Vector<int>& lineCount)
{
    int prevEarliestIndex = 0;

    for(int i = 1; i < logs.GetSize(); i++)
    {
        if(logs[i][lineCount[i]].m_date < logs[prevEarliestIndex][lineCount[prevEarliestIndex]].m_date)
        {
            prevEarliestIndex = i;
        }
        else if(logs[i][lineCount[i]].m_date == logs[prevEarliestIndex][lineCount[prevEarliestIndex]].m_date && logs[i][lineCount[i]].m_time < logs[prevEarliestIndex][lineCount[prevEarliestIndex]].m_time)
        {
            prevEarliestIndex = i;
        }
    }

    return prevEarliestIndex;
}

//----------------------------------------------------------------------------
KeyValue<int, WeatherRecType> assignRecKey(int key, WeatherRecType& rec)
{
    KeyValue<int, WeatherRecType> indexRec;
    indexRec.m_key = key;
    indexRec.m_value = rec;

    return indexRec;
}

//----------------------------------------------------------------------------
void RemoveCompletedFiles(Vector<WeatherLogType> &logs, Vector<int> &lineCount)
{
    for(int i = 0; i < logs.GetSize(); i++)
    {
        if(lineCount[i] == logs[i].GetSize())
        {
            RemoveFromVector(logs, i);
            RemoveFromVector(lineCount, i);
        }
    }
}
