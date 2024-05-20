#ifndef WEATHERMENUOPTIONS_H_INCLUDED
#define WEATHERMENUOPTIONS_H_INCLUDED

#include "../includes/WeatherRec.h"

    /**
    * @namespace WeatherMenuStrategy
    * @todo Documentation
    * @todo Encapsulate each menu in own namespace. Maybe separate into files with helper functions
    */

namespace WeatherMenuStrategy
{
        /**
         * @namespace WindSpeedStrategy
         * @todo Documentation
         */
    namespace WindSpeedStrategy
    {
        void Execute(WeatherLogType &weatherLog);
    }

        /**
         * @namespace TemperatureStrategy
         * @todo Documentation
         */
    namespace TemperatureStrategy
    {
        void Execute(WeatherLogType &weatherLog);
    }

        /**
         * @namespace SolarRadiationStrategy
         * @todo Documentation
         */
    namespace SolarRadiationStrategy
    {
        void Execute(WeatherLogType &weatherLog);
    }

        /**
         * @namespace PrintToFileStrategy
         * @todo Documentation
         */
    namespace PrintToFileStrategy
    {
        void Execute(WeatherLogType &weatherLog);
    }
}

#endif // WEATHERMENUOPTIONS_H_INCLUDED
