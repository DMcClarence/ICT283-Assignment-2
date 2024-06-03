// WeatherMenu.h - WeatherMenu functions definition/interface
//---------------------------------------------------------------------------------

#ifndef WEATHERMENU_H_INCLUDED
#define WEATHERMENU_H_INCLUDED

//---------------------------------------------------------------------------------

#include "../WeatherRec/WeatherRec.h"
#include "../Map/Map.h"
#include "../BST/BST.h"

//---------------------------------------------------------------------------------

    /**
	 * @namespace WeatherMenu
	 * @brief  Encapsulates function to Run the Weather Menu
	 *
	 *
	 * @author 34085068
	 * @version 01
	 * @date 18/04/2024 Started
     *
	 * @author 34085068
	 * @version 02
	 * @date 03/06/2024 Encapsulate into Namespace
	 */

namespace WeatherMenu
{
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
    void RunWeatherMenu(WeatherLogType &weatherLog, Map<int, Map<int, Vector<int>>> &myMap, BST<int> &myBst);
}

//---------------------------------------------------------------------------------

#endif // WEATHERMENU_H_INCLUDED

//---------------------------------------------------------------------------------
