// weatherRec.h - Weather Record definition/interface

//---------------------------------------------------------------------------------

#ifndef WEATHERREC_H_INCLUDED
#define WEATHERREC_H_INCLUDED

//---------------------------------------------------------------------------------

#include "../Date/Date.h"
#include "../Time/Time.h"
#include "../Vector/Vector.h"

//---------------------------------------------------------------------------------

    /**
	 * @struct WeatherRecType
	 * @brief  Defines WeatherRecType and Corresponding Vector
	 *
	 * @author 34085068
	 * @version 01
	 * @date 13/04/2024 34085068, Started
	 */
typedef struct
{
        /// Date of Record
    Date m_date;

        /// Time of Record
    Time m_time;

        /// Wind Speed Recorded in m/s
    float m_s;

        /// Temperature Recorded in degrees C
    float m_t;

        /// Average Solar Radiation Recorded in W/m^2
    float m_sr;

}WeatherRecType;

//---------------------------------------------------------------------------------

    // Defines a type of  Vector of WeatherRecType
typedef Vector<WeatherRecType> WeatherLogType;

//---------------------------------------------------------------------------------

#endif // WEATHERREC_H_INCLUDED

//---------------------------------------------------------------------------------
