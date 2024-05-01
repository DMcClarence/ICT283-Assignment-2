#include "MenuTest.h"

#include "../includes/WindSpeedMenuOption.h"
#include "../includes/TemperatureMenuOption.h"
#include "../includes/SolarRadiationMenuOption.h"
#include "../includes/PrintToFileMenuOption.h"
#include "../includes/WeatherMenuContext.h"
#include "../includes/WeatherRecIO.h"

#include <fstream>

using std::ifstream;

int TestWindSpeedMenuOption()
{
    WindSpeedMenuOption windOption;
    ifstream testFile("data/MetData_Mar01-2014-Mar01-2015-ALL.csv");
    WeatherLogType testLog;

    testFile >> testLog;

    testFile.close();

    windOption.Execute(testLog);

    return 0;
}

int TestTemperatureMenuOption()
{
    TemperatureMenuOption tempOption;
    ifstream testFile("data/MetData_Mar01-2014-Mar01-2015-ALL.csv");
    WeatherLogType testLog;

    testFile >> testLog;

    testFile.close();

    tempOption.Execute(testLog);

    return 0;
}

int TestSolarRadiationMenuOption()
{
    SolarRadiationMenuOption srOption;
    ifstream testFile("data/MetData_Mar01-2014-Mar01-2015-ALL.csv");
    WeatherLogType testLog;

    testFile >> testLog;

    testFile.close();

    srOption.Execute(testLog);

    return 0;
}

int TestPrintToFileMenuOption()
{
    PrintToFileMenuOption ptfOption;
    ifstream testFile("data/MetData_Mar01-2014-Mar01-2015-ALL.csv");
    WeatherLogType testLog;

    testFile >> testLog;

    testFile.close();

    ptfOption.Execute(testLog);

    return 0;
}

int TestWeatherMenuStrategyContext()
{
    WeatherMenuContext menu;
    WindSpeedMenuOption windOption;
    TemperatureMenuOption tempOption;
    SolarRadiationMenuOption srOption;
    ifstream testFile("../data/MetData_Mar01-2015-Mar01-2016-ALL.csv");
    WeatherLogType testLog;

    testFile >> testLog;

    testFile.close();

    menu.SetWeatherMenuStrategy(&windOption);
    menu.ExecuteWeatherMenuOption(testLog);

    menu.SetWeatherMenuStrategy(&tempOption);
    menu.ExecuteWeatherMenuOption(testLog);

    menu.SetWeatherMenuStrategy(&srOption);
    menu.ExecuteWeatherMenuOption(testLog);

    return 0;
}
