// WeatherMenu.h - WeatherMenu functions definition/interface
//---------------------------------------------------------------------------------

#ifndef WEATHERMENU_H_INCLUDED
#define WEATHERMENU_H_INCLUDED

//---------------------------------------------------------------------------------

#include "WeatherMenuContext.h"
#include "WeatherRec.h"

//---------------------------------------------------------------------------------

    /**
	 * @file WeatherMenu.h
	 * @brief  Defines functions to Run the Weather Menu
	 *
	 *
	 * @author 34085068
	 * @version 01
	 * @date 18/04/2024 Started
	 */

    /**
     * @brief  Runs the Weather Menu.
     *
     * RunWeatherMenu displays the Weather Menu Options to the User,
     * Gets their selection, and executes their selection.
     * This functions runs until the user chooses to exit (By entering '5').
     *
     *
     * @param weatherLog - A Vector Containing WeatherRecType Objects
     * @return void
     */
void RunWeatherMenu(WeatherLogType &weatherLog);

//---------------------------------------------------------------------------------

#endif // WEATHERMENU_H_INCLUDED

//---------------------------------------------------------------------------------
