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
#include "../includes/WeatherMenuOptions.h"

#include <iostream>

//----------------------------------------------------------------------------
// Global variables/defines

//----------------------------------------------------------------------------
// Implementation Helper Function Prototypes

    // Dedicated to Displaying the Weather Menu Options to the User
void DisplayWeatherMenu();

    // Dedicated to Executing the Weather Menu Option selected by the User
void ExecuteSelection(int selection, WeatherMenuContext &progMenu, const Vector<void (*)(WeatherLogType&)> &menuOptions, WeatherLogType &weatherLog);

//----------------------------------------------------------------------------
// Function implementations

void RunWeatherMenu(WeatherLogType &weatherLog)
{
    Vector<void (*)(WeatherLogType&)> menuOptions;
    menuOptions.PushBack(WindSpeedMenu::WindSpeedMenuOption);
    menuOptions.PushBack(TemperatureMenu::TemperatureMenuOption);
    menuOptions.PushBack(SolarRadiationMenu::SolarRadiationMenuOption);
    menuOptions.PushBack(PrintToFileMenu::PrintToFileMenuOption);

    WeatherMenuContext progMenu;
    int selection;
    do
    {
        DisplayWeatherMenu();
        std::cin >> selection;
        std::cin.clear();
        std::cout << std::endl;
        ExecuteSelection(selection, progMenu, menuOptions, weatherLog);
    }while(selection != 5);

    std::cout << "Program Exiting..." << std::endl;
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
void ExecuteSelection(int selection, WeatherMenuContext &progMenu, const Vector<void (*)(WeatherLogType&)> &menuOptions, WeatherLogType &weatherLog)
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
    }
}

//----------------------------------------------------------------------------
