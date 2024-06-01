#ifndef WEATHERMENUOPTIONS_H_INCLUDED
#define WEATHERMENUOPTIONS_H_INCLUDED

#include "../includes/WeatherRec.h"
#include "BST.h"
#include <map>

#include "WeatherRecIO.h"

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
        void Execute(WeatherLogType &weatherLog, Map<int, Map<int, Vector<int>>> &myMap, BST<int> &myBst);
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
        void Execute(WeatherLogType &weatherLog, Map<int, Map<int, Vector<int>>> &myMap, BST<int> &myBst);
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
        void Execute(WeatherLogType &weatherLog, Map<int, Map<int, Vector<int>>> &myMap, BST<int> &myBst);
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
        void Execute(WeatherLogType &weatherLog, Map<int, Map<int, Vector<int>>> &myMap, BST<int> &myBst);
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
        void Execute(WeatherLogType &weatherLog, Map<int, Map<int, Vector<int>>> &myMap, BST<int> &myBst);
    }
}

#endif // WEATHERMENUOPTIONS_H_INCLUDED
