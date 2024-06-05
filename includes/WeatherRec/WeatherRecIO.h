// WeatherRecIO.h - Weather Record IO functions definition/interface
//---------------------------------------------------------------------------------

#ifndef WEATHERRECIO_H_INCLUDED
#define WEATHERRECIO_H_INCLUDED

//---------------------------------------------------------------------------------

#include "WeatherRec.h"
#include "../Stack/Stack.h"
#include "WeatherDataStorage.h"

#include <iostream>
#include <string>

//---------------------------------------------------------------------------------
        /**
         * @namespace WeatherRecIO
         * @brief  Encapsulates functions for reading data into WindRecType
         *
         * @author 34085068
         * @version 01
         * @date 14/04/2024 34085068, Started
         *
         * @author 34085068
         * @version 02
         * @date 03/06/2024 34085068, Encapuslate in Namespace
         */
namespace WeatherRecIO
{
            /**
             * @brief  Gets the name of the Data File from the data_source.txt file.
             *
             *
             * @param dataFileName - std::string variable to store the name of the Data File
             * @return bool - Returns true if Successful. Returns False if Failed.
             */
    bool GetDataFileNameFromSrcFile(Stack<std::string> &fileNameStack);

            /**
             * @brief  Reads the Data file into a Vector of WeatherRecType Objects.
             *
             *
             * @param filename - The name of the Data file
             * @param weatherLog - The Vector to Read the Data into
             * @return bool - Returns true if Successful. Returns False if Failed.
             */
    bool ReadWeatherDataFromFiles(Stack<std::string> &fileStack, WeatherDataStorage& weatherData);
}

    /**
     * @brief  Reads an std::istream object into a date object.
     *
     * Format of data in the std::istream object must be in the following format:
     * "D/M/YYYY"
     *
     *
     * @param input - The std::istream object
     * @param d - The date object
     * @return std::istream - The std::istream object
     */
std::istream& operator>>(std::istream& input, Date& d);

    /**
     * @brief  Reads an std::istream object into a time object.
     *
     * Format of data in the std::istream object must be in the following format:
     * "H:MM"
     *
     *
     * @param input - The std::istream object
     * @param t - The time object
     * @return std::istream - The std::istream object
     */
std::istream& operator>>(std::istream& input, Time& t);

        /**
         * @brief  Reads an std::istream object into a Vector of WeatherRecType.
         *
         *
         * @param input - The std::istream object
         * @param data - Vector of WeatherRecType
         * @return std::istream - The std::istream object
         */
std::istream& operator>>(std::istream& input, WeatherLogType& data);

//---------------------------------------------------------------------------------

#endif // WEATHERRECIO_H_INCLUDED

//---------------------------------------------------------------------------------
