#ifndef WEATHERMENUOPTIONS_H_INCLUDED
#define WEATHERMENUOPTIONS_H_INCLUDED

#include "../includes/WeatherRec.h"

    /**
    * @todo Documentation
    * @todo Encapsulate each menu in own namespace.
    */

void WindSpeedMenuOption(WeatherLogType &weatherLog);
void TemperatureMenuOption(WeatherLogType &weatherLog);
void SolarRadiationMenuOption(WeatherLogType &weatherLog);
void PrintToFileMenuOption(WeatherLogType &weatherLog);

#endif // WEATHERMENUOPTIONS_H_INCLUDED
