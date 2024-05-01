// SolarRadiationMenuOption.h - SolarRadiationMenuOption class definition/interface
//---------------------------------------------------------------------------------

#ifndef SOLARRADIATIONMENUOPTION_H_INCLUDED
#define SOLARRADIATIONMENUOPTION_H_INCLUDED

//---------------------------------------------------------------------------------

#include "WeatherMenuStrategy.h"

//---------------------------------------------------------------------------------

    /**
	 * @class SolarRadiationMenuOption
	 * @brief  Menu Option for Solar Radiation Data
	 *
	 * SolarRadiationMenuOption is derived from the WeatherMenuStrategy Abstract Class
	 *
	 * @author 34085068
	 * @version 01
	 * @date 17/04/2024 Started
	 */
class SolarRadiationMenuOption: public WeatherMenuStrategy
{
    public:
            /**
             * @brief  Default Constructor for SolarRadiationMenuOption Object.
             *
             *
             */
        SolarRadiationMenuOption();

            /**
             * @brief  Executes the Solar Radiation Menu Option.
             *
             * User will be prompted for a Year.
             * The Total Solar Radiation for each Month of that Year will be displayed to the screen.
             *
             *
             * @param weatherLog - A Vector Containing WeatherRecType Objects
             * @return void
             */
        void Execute(WeatherLogType &weatherLog) override;
};

//---------------------------------------------------------------------------------

#endif // SOLARRADIATIONMENUOPTION_H_INCLUDED

//---------------------------------------------------------------------------------
