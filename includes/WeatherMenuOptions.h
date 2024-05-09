#ifndef WEATHERMENUOPTIONS_H_INCLUDED
#define WEATHERMENUOPTIONS_H_INCLUDED

#include "../includes/WeatherRec.h"

    /**
    * @todo Documentation
    * @todo Encapsulate each menu in own namespace. Maybe separate into files with helper functions
    */

namespace WindSpeedMenu
{
    void WindSpeedMenuOption(WeatherLogType &weatherLog);
}

namespace TemperatureMenu
{
    void TemperatureMenuOption(WeatherLogType &weatherLog);
}

namespace SolarRadiationMenu
{
    void SolarRadiationMenuOption(WeatherLogType &weatherLog);
}

namespace PrintToFileMenu
{
    void PrintToFileMenuOption(WeatherLogType &weatherLog);
}


#endif // WEATHERMENUOPTIONS_H_INCLUDED
