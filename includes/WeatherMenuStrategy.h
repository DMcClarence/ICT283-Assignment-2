// WeatherMenuStrategy.h - WeatherMenuStrategy abstract class definition/interface
//---------------------------------------------------------------------------------

#ifndef WEATHERMENUSTRATEGY_H_INCLUDED
#define WEATHERMENUSTRATEGY_H_INCLUDED

//---------------------------------------------------------------------------------

#include "WeatherRec.h"
#include <new>

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
     *
	 * @author 34085068
	 * @version 02
	 * @date 29/04/2024 Override operator new and operator new[] to prevent dynamic memory allocation.
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

            /**
             * @brief  Creates a WeatherMenuStrategy on the Heap.
             *
             * In the WeatherMenuStrategy, the new operator is deleted to prevent
             * WeatherMenuStrategy objects from being allocated on the Heap.
             *
             *
             * @param size - The amount of memory in bytes.
             * @return void*
             */
        void* operator new(std::size_t size) = delete;

            /**
             * @brief  Creates a WeatherMenuStrategy on the Heap.
             *
             * In the WeatherMenuStrategy, the new operator is deleted to prevent
             * WeatherMenuStrategy objects from being allocated on the Heap.
             *
             *
             * @param size - The amount of memory in bytes.
             * @return void*
             */
        void* operator new[](std::size_t size) = delete;
};

//---------------------------------------------------------------------------------

#endif // WEATHERMENUSTRATEGY_H_INCLUDED

//---------------------------------------------------------------------------------
