// WeatherRecUtilities.h - Weather Record Utility functions definition/interface
//---------------------------------------------------------------------------------

#ifndef WEATHERRECUTILITIES_H_INCLUDED
#define WEATHERRECUTILITIES_H_INCLUDED

//---------------------------------------------------------------------------------

#include "WeatherRec.h"

#include <string>

using std::string;

//---------------------------------------------------------------------------------

    /**
	 * @file WeatherRecUtilities.h
	 * @brief  Defines WeatherRecType and WeatherLogType Utility Functions
	 *
	 * @author 34085068
	 * @version 01
	 * @date 13/04/2024 34085068, Started
	 *
	 * @author 34085068
	 * @version 02
	 * @date 04/05/2024 34085068, Add comparison operator overloads to allow for Weather Record to be sorted
	 */

    /**
     * @brief  Extracts float values from a WeatherLogType object during a specified period.
     *
     *
     * @param  weatherLog - The WeatherLogType object for values to be extracted from
     * @param  month - The month of values to be extracted
     * @param  year - The year of values to be extracted
     * @param  WeatherRecType::*p_member - The WeatherRecType member to be extracted
     * @param  extractedValues - float Vector to store the values in
     * @return void
     */
void ExtractValuesFromWeatherLog(WeatherLogType &weatherLog, int month, int year,
                                    float WeatherRecType::*p_member, Vector<float> &extractedValues);

    /**
     * @brief  Converts a month from an int to a string
     *
     *
     * @param  month - The numerical month to be converted
     * @return string
     */
string MonthToString(int month);

    /**
     * @brief  Converts Speed from m/s to km/h
     *
     *
     * @param  speed - The Speed in m/s
     * @return string
     */
void ToKMperHr(float &speed);

    /**
     * @brief  Converts Solar Radiation from W/m^2 to kWh/m^2
     *
     *
     * @param  solarRad - The Solar Radiation on W/m^2
     * @return string
     */
void TokWh(float &solarRad);

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
bool operator==(WeatherRecType &left, WeatherRecType &right);

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
bool operator<(WeatherRecType &left, WeatherRecType &right);

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
bool operator<=(WeatherRecType &left, WeatherRecType &right);

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
bool operator>(WeatherRecType &left, WeatherRecType &right);

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
bool operator>=(WeatherRecType &left, WeatherRecType &right);

    /**
     * @brief  Removes duplicate Weather Records from a Weather Log
     *
     *
     * @param log - The Weather Log
     * @return void
     */
void RemoveDuplicatesFromWeatherLog(WeatherLogType &log);
//---------------------------------------------------------------------------------

#endif // WEATHERRECUTILITIES_H_INCLUDED

//---------------------------------------------------------------------------------
