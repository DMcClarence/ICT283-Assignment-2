#ifndef WEATHERMENUOPTIONS_H_INCLUDED
#define WEATHERMENUOPTIONS_H_INCLUDED

#include "../WeatherRec/WeatherDataStorage.h"

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
     */
namespace WeatherMenuStrategy
{
        /**
         * @namespace WeatherMenuStrategy::WeatherMenuContext
         * @brief  Encapsulates the Initialisation of the Strategy Context
         *
         *
         * @author 34085068
         * @version 01
         * @date 15/05/2024 Started
         */
    namespace WeatherMenuContext
    {
            /**
             * @brief  Initialise the Weather Menu Strategy Context
             *
             * Adds the Menu Options to a Vector
             *
             *
             * @param menuOptions - A Vector containing the Execution functions of the Weather Menu Strategy
             * @return Vetcor<void (*)(WeatherDataStorage)&>& - The Menu Options Vector
             */
        Vector<void (*)(WeatherDataStorage&)>& InitWeatherMenuContext(Vector<void (*)(WeatherDataStorage&)>& menuOptions);
    }
        /**
         * @namespace WeatherMenuStrategy::WindSpeedStrategy
         * @brief  Encapsulates Wind Menu's Execute Function
         *
         *
         * @author 34085068
         * @version 01
         * @date 15/05/2024 Started
         */
    namespace WindSpeedStrategy
    {
            /**
             * @brief  Executes the Wind Speed Menu Option
             *
             *
             * @param weatherData - Data structure containing the weather data
             * @return void
             */
        void Execute(WeatherDataStorage& weatherData);
    }

        /**
         * @namespace WeatherMenuStrategy::TemperatureStrategy
         * @brief  Encapsulates Temperatures's Execute Function
         *
         *
         * @author 34085068
         * @version 01
         * @date 15/05/2024 Started
         */
    namespace TemperatureStrategy
    {
            /**
             * @brief  Executes the Temperature Menu Option
             *
             *
             * @param weatherData - Data structure containing the weather data
             * @return void
             */
        void Execute(WeatherDataStorage& weatherData);
    }

        /**
         * @namespace WeatherMenuStrategy::SolarRadiationStrategy
         * @brief  Encapsulates Solar Radiations's Execute Function
         *
         *
         * @author 34085068
         * @version 01
         * @date 15/05/2024 Started
         */
    namespace SolarRadiationStrategy
    {
            /**
             * @brief  Executes the Solar Radiation Menu Option
             *
             *
             * @param weatherData - Data structure containing the weather data
             * @return void
             */
        void Execute(WeatherDataStorage& weatherData);
    }

        /**
         * @namespace WeatherMenuStrategy::SPCCStrategy
         * @brief  Encapsulates sPCC's Execute Function
         *
         *
         * @author 34085068
         * @version 01
         * @date 15/05/2024 Started
         */
    namespace SPCCStrategy
    {
            /**
             * @brief  Executes the sample Pearson Correlation Coefficient Menu Option
             *
             *
             * @param weatherData - Data structure containing the weather data
             * @return void
             */
        void Execute(WeatherDataStorage& weatherData);
    }

        /**
         * @namespace WeatherMenuStrategy::is PrintToFileStrategy
         * @brief  Encapsulates Print to File's Execute Function
         *
         *
         * @author 34085068
         * @version 01
         * @date 15/05/2024 Started
         */
    namespace PrintToFileStrategy
    {
            /**
             * @brief  Executes the Print to File Menu Option
             *
             *
             * @param weatherData - Data structure containing the weather data
             * @return void
             */
        void Execute(WeatherDataStorage& weatherData);
    }
}

#endif // WEATHERMENUOPTIONS_H_INCLUDED
