// WeatherRecUtilities.h - Weather Record Utility functions definition/interface
//---------------------------------------------------------------------------------

#ifndef WEATHERRECUTILITIES_H_INCLUDED
#define WEATHERRECUTILITIES_H_INCLUDED

//---------------------------------------------------------------------------------

#include "WeatherRec.h"
#include <string>

//---------------------------------------------------------------------------------

    /**
	 * @namespace WeatherRecUtilities
	 * @brief  Defines WeatherRecType and WeatherLogType Utility Functions
	 *
	 * @author 34085068
	 * @version 01
	 * @date 13/04/2024 34085068, Started
	 *
	 * @author 34085068
	 * @version 02
	 * @date 04/05/2024 34085068, Add comparison operator overloads to allow for Weather Record to be sorted
     *
	 * @author 34085068
	 * @version 03
	 * @date 03/06/2024 34085068, Encapsulate into a namespace
	 */
namespace WeatherRecUtilities
{
        /**
         * @brief  Extracts float values from a WeatherLogType object during a specified period.
         *
         *
         * @param  weatherLog - The WeatherLogType object for values to be extracted from
         * @param  month - The month of values to be extracted
         * @param  year - The year of values to be extracted
         * @param  WeatherRecType::*p_member - The WeatherRecType member to be extracted
         * @return Vector<float> - The vector of extracted float values
         */
    Vector<float> ExtractValuesFromWeatherLog(WeatherLogType &weatherLog, int month, int year, float WeatherRecType::*p_member);

        /**
         * @brief  Extracts float values from a WeatherLogType object.
         *
         *
         * @param  weatherLog - The WeatherLogType object for values to be extracted from
         * @param  WeatherRecType::*p_member - The WeatherRecType member to be extracted
         * @return Vector<float> - The vector of extracted float values
         */
    Vector<float> ExtractValuesFromWeatherLog(WeatherLogType &weatherLog, float WeatherRecType::*p_member);

        /**
         * @brief  Removes any Data values that aren't valid.
         *
         * Looks specifically for values of NaN
         *
         * @param  data - Vector of Data Values
         * @return Vector<float> - The modified Vector
         */
    Vector<float>& RemoveInvalidData(Vector<float> &data);

        /**
         * @brief  Removes any Data values that aren't valid from a pair of Data Vectors.
         *
         * If an element in either Vector is invalid, that element is removed from both Vectors
         * to ensure the data from each record matches up.
         *
         * Looks specifically for values of NaN.
         *
         * @param  data - The pair of Vectors of Data Values
         * @return std::pair<Vector<float>, Vector<float>> - The modified Pair of Vectors
         */
    std::pair<Vector<float>, Vector<float>>& RemoveInvalidDataFromDataPairs(std::pair<Vector<float>, Vector<float>>& data);

        /**
         * @brief  Converts a month from an int to a string
         *
         *
         * @param  month - The numerical month to be converted
         * @return std::string - The numerical month as an English String
         */
    std::string MonthToString(int month);

        /**
         * @brief  Converts Speed from m/s to km/h
         *
         *
         * @param  speed - The Speed in m/s
         * @return float - The Speed in km/hr
         */
    float& ToKMperHr(float &speed);

        /**
         * @brief  Converts Solar Radiation from W/m^2 to kWh/m^2
         *
         *
         * @param  solarRad - The Solar Radiation in W/m^2
         * @return float - The Solar Radiation in kWh/m^2
         */
    float& TokWh(float &solarRad);

        /**
         * @brief  Removes duplicate Weather Records from a Weather Log
         *
         *
         * @param log - The Weather Log
         * @return void
         */
    void RemoveDuplicatesFromWeatherLog(WeatherLogType &log);

        /**
         * @brief  Creates a Key for the Month/Year Pair of the Record.
         *
         * Key is a Concat of the Year followed by the Month.
         *
         * @param year - The Year of the Record
         * @param month - The Month pf the Record
         * @return int - The Created Key
         */
        //
    int CreateMonthYearKey(int year, int month);
}

    /**
     * @brief  Compares Weather Records for equality.
     *
     * Uses the Date and Time for the check. Assumes that if the date and time matches,
     * the data in each record will also be equal meaning they are the same record.
     *
     *
     * @param left - Weather Record to compare
     * @param right - Weather Record to be compared against
     * @return bool - Returns true if Weather Records Date and Times are Equal. Otherwise returns false.
     */
bool operator==(const WeatherRecType &left, const WeatherRecType &right);

    /**
     * @brief  Compares Weather Records for inequality.
     *
     * Uses the Date and Time for the check. If one or the other is not equal,
     * then they are different records.
     *
     *
     * @param left - Weather Record to compare
     * @param right - Weather Record to be compared against
     * @return bool - Returns true if Weather Records Date and Times are not equal. Otherwise returns false.
     */
bool operator!=(const WeatherRecType &left, const WeatherRecType &right);

    /**
     * @brief  Checks if a Weather Record is less than another Weather Record
     *
     * Uses the Date and Time for the check.
     *
     *
     * @param left - Weather Record to compare
     * @param right - Weather Record to be compared against
     * @return bool - Returns true if Weather Record Date or Time is less than another Weather Record. Otherwise returns false.
     */
bool operator<(const WeatherRecType &left, const WeatherRecType &right);

    /**
     * @brief  Checks if a Weather Record is less than or equal to another Weather Record
     *
     * Uses the Date and Time for the check. Assumes that if the date and time matches,
     * the data in each record will also be equal meaning they are the same record.
     *
     *
     * @param left - Weather Record to compare
     * @param right - Weather Record to be compared against
     * @return bool - Returns true if Weather Record Date or Time is less than another Weather Record,
     *                  or Weather Records Date and Times are equal. Otherwise returns false.
     */
bool operator<=(const WeatherRecType &left, const WeatherRecType &right);

    /**
     * @brief  Checks if a Weather Record is greater than another Weather Record
     *
     * Uses the Date and Time for the check.
     *
     *
     * @param left - Weather Record to compare
     * @param right - Weather Record to be compared against
     * @return bool - Returns true if Weather Record Date or Time is greater than another Weather Record. Otherwise returns false.
     */
bool operator>(const WeatherRecType &left, const WeatherRecType &right);

    /**
     * @brief  Checks if a Weather Record is greater than or equal to another Weather Record
     *
     * Uses the Date and Time for the check. Assumes that if the date and time matches,
     * the data in each record will also be equal meaning they are the same record.
     *
     *
     * @param left - Weather Record to compare
     * @param right - Weather Record to be compared against
     * @return bool - Returns true if Weather Record Date or Time is greater than another Weather Record,
     *                  or Weather Records Date and Times are equal. Otherwise returns false.
     */
bool operator>=(const WeatherRecType &left, const WeatherRecType &right);

//---------------------------------------------------------------------------------

#endif // WEATHERRECUTILITIES_H_INCLUDED

//---------------------------------------------------------------------------------
