// WeatherMenu.cpp
//
// Implementation of WeatherMenu functions
//
// Version
// 01 18/04/2024 34085068
//      Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "../includes/WeatherMenu.h"
#include "../includes/WindSpeedMenuOption.h"
#include "../includes/TemperatureMenuOption.h"
#include "../includes/SolarRadiationMenuOption.h"
#include "../includes/PrintToFileMenuOption.h"

#include <iostream>

//----------------------------------------------------------------------------
// Global variables/defines

//----------------------------------------------------------------------------
// Implementation Helper Function Prototypes

    // Dedicated to Displaying the Weather Menu Options to the User
void DisplayWeatherMenu();

int GetUserSelection();

    // Dedicated to Executing the Weather Menu Option selected by the User
void ExecuteSelection(int selection, WeatherMenuContext &progMenu, const Vector<WeatherMenuStrategy*> &menuOptions, WeatherLogType &weatherLog);

//----------------------------------------------------------------------------
// Function implementations

void RunWeatherMenu(WeatherLogType &weatherLog)
{
    Vector<WeatherMenuStrategy*> menuOptions;
    WindSpeedMenuOption windSpeedOption;
    menuOptions.PushBack(&windSpeedOption);

    TemperatureMenuOption tempOption;
    menuOptions.PushBack(&tempOption);

    SolarRadiationMenuOption solarRadOption;
    menuOptions.PushBack(&solarRadOption);

    PrintToFileMenuOption ptfOption;
    menuOptions.PushBack(&ptfOption);

    WeatherMenuContext progMenu;
    int selection;

    do
    {
        DisplayWeatherMenu();
        selection = GetUserSelection();
        ExecuteSelection(selection, progMenu, menuOptions, weatherLog);
    }while(selection != 5);
}

//----------------------------------------------------------------------------
void DisplayWeatherMenu()
{
    std::cout << "Select an Option from 1 - 5: " << std::endl;
    std::cout << "      1. Display the Mean and Standard Deviation of the Wind Speed from a Specifed Year and Month." << std::endl;
    std::cout << "      2. Display the Mean and Standard Deviation of the Temperature for each Month from a Specified Year." << std::endl;
    std::cout << "      3. Display the Total Solar Radiation for each Month from a Specified Year." << std::endl;
    std::cout << "      4. Display the Mean and Standard Deviation of the Wind Speed and Temperature, and the Total Solar Radiation" << std::endl;
    std::cout << "         for each month of a Specified Year." << std::endl;
    std::cout << "      5. Exit the Program." << std::endl;
    std::cout << "Choice: ";
}

//----------------------------------------------------------------------------
void ExecuteSelection(int selection, WeatherMenuContext &progMenu, const Vector<WeatherMenuStrategy*> &menuOptions, WeatherLogType &weatherLog)
{
    if(selection == 5)
    {
        return;
    }

    if(selection > 0 && selection <= 4)
    {
        progMenu.SetWeatherMenuStrategy(menuOptions[selection - 1]);
        progMenu.ExecuteWeatherMenuOption(weatherLog);
    }
    else
    {
        std::cout << "Invalid Option" << std::endl;
        std::cout << std::endl;
    }
}

//----------------------------------------------------------------------------
int GetUserSelection()
{
    std::string input;
    std::cin >> input;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << std::endl;

    int selection;
    try
    {
        selection = std::stoi(input);
    }
    catch(...)
    {
        return -1;
    }

    return selection;
}

//----------------------------------------------------------------------------
