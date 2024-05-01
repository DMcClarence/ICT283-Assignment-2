// TemperatureMenuOption.h - TemperatureMenuOption class definition/interface
//---------------------------------------------------------------------------------

#ifndef TEMPERATUREMENUOPTION_H_INCLUDED
#define TEMPERATUREMENUOPTION_H_INCLUDED

//---------------------------------------------------------------------------------

#include "WeatherMenuStrategy.h"

//---------------------------------------------------------------------------------

    /**
	 * @class TemperatureMenuOption
	 * @brief  Menu Option for Temperature Data
	 *
	 * TemperatureMenuOption is derived from the WeatherMenuStrategy Abstract Class
	 *
	 * @author 34085068
	 * @version 01
	 * @date 17/04/2024 Started
	 */
class TemperatureMenuOption: public WeatherMenuStrategy
{
    public:
            /**
             * @brief  Default Constructor for TemperatureMenuOption Object.
             *
             *
             */
        TemperatureMenuOption();

            /**
             * @brief  Executes the Temperature Menu Option.
             *
             * User will be prompted for a Year.
             * The Temperature Average and Standard Deviation for each Month of that Year
             * will be displayed to the screen.
             *
             *
             * @param weatherLog - A Vector Containing WeatherRecType Objects
             * @return void
             */
        void Execute(WeatherLogType &weatherLog) override;
};

//---------------------------------------------------------------------------------

#endif // TEMPERATUREMENUOPTION_H_INCLUDED

//---------------------------------------------------------------------------------
