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

#include "../../includes/WeatherMenu/WeatherMenu.h"
#include "../../includes/WeatherMenu/WeatherMenuOptions.h"

#include <iostream>

//----------------------------------------------------------------------------
// Global variables/defines

//----------------------------------------------------------------------------
// Implementation Helper Function Prototypes

    // Dedicated to Displaying the Weather Menu Options to the User
void DisplayWeatherMenu();

    // Dedicated to Recieving User Selection and Returning to Client as an int
int GetUserSelection();

    // Dedicated to Executing the Weather Menu Option selected by the User
void ExecuteSelection(int selection, const Vector<void (*)(WeatherDataStorage&)>& menuOptions, WeatherDataStorage& weatherData);

//----------------------------------------------------------------------------
// Function implementations

void WeatherMenu::RunWeatherMenu(WeatherDataStorage& weatherData)
{
        // Set Up Weather Menu Strategy Context
    Vector<void (*)(WeatherDataStorage&)> menuOptions;
    WeatherMenuStrategy::WeatherMenuContext::InitWeatherMenuContext(menuOptions);

    int selection;
    do
    {
        DisplayWeatherMenu();
        selection = GetUserSelection();
        ExecuteSelection(selection, menuOptions, weatherData);
    }while(selection != 5);
}

//----------------------------------------------------------------------------
void DisplayWeatherMenu()
{
    std::cout << "Select an Option from 1 - 5: " << std::endl;
    std::cout << "      1. Display the Mean and Standard Deviation of the Wind Speed from a Specifed Year and Month." << std::endl;
    std::cout << "      2. Display the Mean and Standard Deviation of the Temperature for each Month from a Specified Year." << std::endl;
    std::cout << "      3. Display the Sample Pearson Correlation Coefficients of Wind Speed/Temperature(S_T), " << std::endl;
    std::cout << "         Wind Speed/Solar Radiation(S_R), and Temperature/Solar Radiation(T_R)." << std::endl;
    std::cout << "      4. Display the Mean, Standard Deviation, and Mean Absolute Deviation of the Wind Speed and Temperature, " << std::endl;
    std::cout << "         and the Total Solar Radiation for each month of a Specified Year." << std::endl;
    std::cout << "      5. Exit the Program." << std::endl;
    std::cout << "Choice: ";
}

//----------------------------------------------------------------------------
void ExecuteSelection(int selection, const Vector<void (*)(WeatherDataStorage&)>& menuOptions, WeatherDataStorage& weatherData)
{
    if(selection == 5)
    {
        return;
    }

    if(selection > 0 && selection <= 4)
    {
        menuOptions[selection - 1](weatherData);
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
