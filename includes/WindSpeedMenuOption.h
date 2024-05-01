// WindSpeedMenuOption.h - WindSpeedMenuOption class definition/interface
//---------------------------------------------------------------------------------

#ifndef WINDSPEEDMENUOPTION_H_INCLUDED
#define WINDSPEEDMENUOPTION_H_INCLUDED

//---------------------------------------------------------------------------------

#include "WeatherMenuStrategy.h"

//---------------------------------------------------------------------------------

    /**
	 * @class WindSpeedMenuOption
	 * @brief  Menu Option for Wind Speed Data
	 *
	 * WindSpeedMenuOption is derived from the WeatherMenuStrategy Abstract Class
	 *
	 * @author 34085068
	 * @version 01
	 * @date 17/04/2024 Started
	 */
class WindSpeedMenuOption: public WeatherMenuStrategy
{
    public:
            /**
             * @brief  Default Constructor for WindSpeedMenuOption Object.
             *
             *
             */
        WindSpeedMenuOption();

            /**
             * @brief  Executes the Wind Speed Menu Option.
             *
             * User will be prompted for a Year followed by a Month.
             * The Wind Speed Average and Standard Deviation for that Month of that Year
             * will be displayed to the screen.
             *
             *
             * @param weatherLog - A Vector Containing WeatherRecType Objects
             * @return void
             */
        void Execute(WeatherLogType &weatherLog) override;
};

//---------------------------------------------------------------------------------

#endif // WINDSPEEDMENUOPTION_H_INCLUDED

//---------------------------------------------------------------------------------
