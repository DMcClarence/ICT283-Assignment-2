// PrintToFileMenuOption.h - PrintToFileMenuOption class definition/interface
//---------------------------------------------------------------------------------

#ifndef PRINTTOFILEMENUOPTION_H_INCLUDED
#define PRINTTOFILEMENUOPTION_H_INCLUDED

//---------------------------------------------------------------------------------

#include "WeatherMenuStrategy.h"

//---------------------------------------------------------------------------------

    /**
	 * @class PrintToFileMenuOption
	 * @brief  Menu Option for Printing Weather Record Data to a File
	 *
	 * PrintToFileMenuOption is derived from the WeatherMenuStrategy Abstract Class
	 *
	 * @author 34085068
	 * @version 01
	 * @date 17/04/2024 Started
	 */
class PrintToFileMenuOption: public WeatherMenuStrategy
{
    public:
            /**
             * @brief  Default Constructor for PrintToFileMenuOption Object.
             *
             *
             */
        PrintToFileMenuOption();

            /**
             * @brief  Executes the Print to File Menu Option.
             *
             * User will be prompted for a Year.
             * The Wind Speed and Temperature Averages and Standard Deviation, as well as
             * the Total Solar Radiation for each Month of that Year will be displayed to the screen.
             *
             *
             * @param weatherLog - A Vector Containing WeatherRecType Objects
             * @return void
             */
        void Execute(WeatherLogType &weatherLog) override;
};

//---------------------------------------------------------------------------------

#endif // PRINTTOFILEMENUOPTION_H_INCLUDED

//---------------------------------------------------------------------------------
