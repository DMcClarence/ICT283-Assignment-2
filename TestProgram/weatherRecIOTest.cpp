#include "WeatherRecIOTest.h"

#include "../includes/WeatherRecIO.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::istringstream;
using std::ifstream;

int TestDateInsertion()
{
    Date d;
    string date = "12/07/2023";
    istringstream dateStream(date);

    dateStream >> d;

    cout << "Day = " << d.GetDay() << endl;
    cout << "Month = " << d.GetMonth() << endl;
    cout << "Year = " << d.GetYear() << endl;
    cout << endl;

    return 0;
}

int TestTimeInsertion()
{
    Time t;
    string time = "12:16";
    istringstream timeStream(time);

    timeStream >> t;

    cout << "Hours = " << t.GetHours() << endl;
    cout << "Minutes = " << t.GetMinutes() << endl;
    cout << "Seconds = " << t.GetSeconds() << endl;
    cout << endl;

    return 0;
}

int TestWeatherLogTypeInsertion()
{
    ifstream testFile("data/MetData-31-3a.csv");
    WeatherLogType testLog;

    testFile >> testLog;

    testFile.close();

    for(int i = 0; i < testLog.GetSize(); i++)
    {
        cout << "Wind Speed = " << testLog[i].m_s << endl;
        cout << "Temp = " << testLog[i].m_t << endl;
        cout << "Solar Radiation = " << testLog[i].m_sr << endl;
    }

    cout << endl;

    return 0;
}

int TestGetDataFileNameFromSrcFile()
{
    string filename;
    GetDataFileNameFromSrcFile(filename);

    cout << "File: " << filename << endl;

    return 0;
}

int TestReadWeatherDataFromFile()
{
    WeatherLogType testLog;
    string filename = "MetData-31-3a.csv";
    bool success = ReadWeatherDataFromFile(filename, testLog);

    if(success)
    {
        cout << "Success" << endl;
    }
    else
    {
        cout << "Fail" << endl;
    }

    return 0;
}
