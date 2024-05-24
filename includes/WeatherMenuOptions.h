#ifndef WEATHERMENUOPTIONS_H_INCLUDED
#define WEATHERMENUOPTIONS_H_INCLUDED

#include "../includes/WeatherRec.h"

    /**
     * @namespace WeatherMenuStrategy
     * @brief  Defines a common namespace for WeatherMenuStrategy function implementations
     *
     *
     * @author 34085068
     * @version 01
	 * @date 01/05/2024 Started
	 *
     * @author 34085068
     * @version 02
	 * @date 15/05/2024 Encapsulate each Menu into namespaces
	 *
     * @todo Maybe separate into files with required helper functions.
     */
namespace WeatherMenuStrategy
{
        /**
         * @namespace WindSpeedStrategy
         * @brief  Encapsulates Wind Menu's Execute Function
         *
         *
         * @author 34085068
         * @version 01
         * @date 15/05/2024 Started
         */
    namespace WindSpeedStrategy
    {
        void Execute(WeatherLogType &weatherLog);
    }

        /**
         * @namespace TemperatureStrategy
         * @brief  Encapsulates Temperatures's Execute Function
         *
         *
         * @author 34085068
         * @version 01
         * @date 15/05/2024 Started
         */
    namespace TemperatureStrategy
    {
        void Execute(WeatherLogType &weatherLog);
    }

        /**
         * @namespace SolarRadiationStrategy
         * @brief  Encapsulates Solar Radiations's Execute Function
         *
         *
         * @author 34085068
         * @version 01
         * @date 15/05/2024 Started
         */
    namespace SolarRadiationStrategy
    {
        void Execute(WeatherLogType &weatherLog);
    }

        /**
         * @namespace SPCCStrategy
         * @brief  Encapsulates sPCC's Execute Function
         *
         *
         * @author 34085068
         * @version 01
         * @date 15/05/2024 Started
         */
    namespace SPCCStrategy
    {
        void Execute(WeatherLogType &weatherLog);
    }

        /**
         * @namespace PrintToFileStrategy
         * @brief  Encapsulates Print to File's Execute Function
         *
         *
         * @author 34085068
         * @version 01
         * @date 15/05/2024 Started
         */
    namespace PrintToFileStrategy
    {
        void Execute(WeatherLogType &weatherLog);
    }
}

#endif // WEATHERMENUOPTIONS_H_INCLUDED
