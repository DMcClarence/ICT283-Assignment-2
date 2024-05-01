// WeatherMenuStrategy.h - WeatherMenuStrategy abstract class definition/interface
//---------------------------------------------------------------------------------

#ifndef WEATHERMENUSTRATEGY_H_INCLUDED
#define WEATHERMENUSTRATEGY_H_INCLUDED

//---------------------------------------------------------------------------------

#include "WeatherRec.h"

//---------------------------------------------------------------------------------

    /**
	 * @interface WeatherMenuStrategy
	 * @brief  An Abstract Class to Implement Different Menu Options for the Weather Program
	 *
	 * WeatherMenuStrategy is designed to be inherited from to implement different Menu Options
	 * in a polymorphic way. Class inheritance is utilised to implement polymorphism.
	 *
	 * @author 34085068
	 * @version 01
	 * @date 17/04/2024 Started
	 */
class WeatherMenuStrategy
{
    public:

            /**
             * @brief  A Virtual Destructor
             *
             *
             * @return virtual
             */
        virtual ~WeatherMenuStrategy();

            /**
             * @brief  A pure Virtual Function designed to be overwritten with each Menu Options implementation.
             *
             *
             * @param weatherLog - A Vector Containing WeatherRecType Objects
             * @return virtual void
             */
        virtual void Execute(WeatherLogType &weatherLog) = 0;
};

//---------------------------------------------------------------------------------

#endif // WEATHERMENUSTRATEGY_H_INCLUDED

//---------------------------------------------------------------------------------
